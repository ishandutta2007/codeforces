#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int M=(int)1e6;
const int N=200010;
struct Treap
{
    struct node
    {
        int l,r; //son
        int cnt,len,siz; //size
        int key; //randomkey
        int d;
        LL st;
        void init(int _len,int _d,LL _st)
        {
            l=r=0;cnt=1;
            key=rand()*rand();
            siz=len=_len;d=_d;st=_st;
        }
        LL last(){return st+(len-1)*d;}
        LL getans(){return min(st,last());}
    }a[N*9];
    int tot;
    int newnode(int len,int d,LL st){tot++;a[tot].init(len,d,st);return tot;}
    int rt[N*3],ti[N*3],rc;
    struct Segment
    {
        int l,r,id;
        bool operator<(const Segment&a)const{return l<a.l;}
    };
    set<Segment>s;
    void update(int x)
    {
        int l=a[x].l,r=a[x].r;
        a[x].cnt=a[l].cnt+a[r].cnt+1;
        a[x].siz=a[l].siz+a[r].siz+a[x].len;
    }
    int merge(int x,int y)
    {
        if (x==0||y==0)return x+y;
        if (a[x].key>a[y].key)
        {
            a[x].r=merge(a[x].r,y);
            update(x);
            return x;
        }
        else
        {
            a[y].l=merge(x,a[y].l);
            update(y);
            return y;
        }
    }
    void split(int t,int k,int &x,int &y)
    {
        if (t==0){x=0; y=0; return;}
        if (a[a[t].l].cnt+1<=k)
        {
            x=t;
            split(a[t].r,k-a[a[t].l].cnt-1,a[t].r,y);
        }
        else 
        {
            y=t;
            split(a[t].l,k,x,a[t].l);
        }
        if (x!=0)update(x);
        if (y!=0)update(y);
    }
    void Init(int pos)
    {
        rt[++rc]=newnode(pos,-1,pos);
        int x=newnode(2*M+10-pos+1,1,0);
        ti[rc]=0;
        rt[rc]=merge(rt[rc],x);
        s.insert({0,2*M+10,rc});
    }
    void Cutl(int x,int k)
    {
        int t;
        for(;k&&rt[x];)
        {
            split(rt[x],1,t,rt[x]);
            if(k<a[t].len)a[t].st+=k*a[t].d,a[t].len-=k,a[t].siz-=k,rt[x]=merge(t,rt[x]),k=0;
            else k-=a[t].len;
        }
    }
    void Cutr(int x,int k)
    {
        int t;
        for(;k&&rt[x];)
        {
            split(rt[x],a[rt[x]].cnt-1,rt[x],t);
            if(k<a[t].len)a[t].len-=k,a[t].siz-=k,rt[x]=merge(rt[x],t),k=0;
            else k-=a[t].len;
        }
    }
    void Cutlr(int x,int y,int l,int r)
    {
        // printf("%d %d %d %d %d %d %d %d\n",x,rt[x],a[rt[x]].siz,y,rt[y],a[rt[y]].siz,l,r);
        int p=rt[x],cnt=0,k=l;
        // printf("%d %d %d\n",a[p].r,a[p].len,a[p].cnt);
        for(;p;)
        if(a[a[p].l].siz>=k)p=a[p].l;
        else
        {
            cnt+=a[a[p].l].cnt;
            k-=a[a[p].l].siz;
            if(a[p].len>=k)break;
            else cnt++,k-=a[p].len,p=a[p].r;
        }
        int t1;
        // printf("%d %d\n",cnt,k);
        split(rt[x],cnt,rt[x],t1);
        split(t1,1,t1,rt[y]);
        // printf("%d %d %d %d %d %d %d %d\n",x,rt[x],a[rt[x]].siz,y,rt[y],a[rt[y]].siz,l,r);
        if(k>1)
        {
            int tmp=newnode(k-1,a[t1].d,a[t1].st);
            a[t1].st+=a[t1].d*(k-1);a[t1].len-=k-1;a[t1].siz-=k-1;
            rt[x]=merge(rt[x],tmp);
        }
        rt[y]=merge(t1,rt[y]);
        Cutl(y,r-l+1);
    }
    int Merge(int x,int y)
    {
        int t1,t2;
        // printf("%d %d\n",a[rt[x]].siz,a[rt[y]].siz);
        split(rt[x],a[rt[x]].cnt-1,rt[x],t1);
        split(rt[y],1,t2,rt[y]);
        if(abs(a[t1].last()-a[t2].st)<=1)
        {
            rt[x]=merge(rt[x],t1);
            rt[x]=merge(rt[x],t2);
            rt[x]=merge(rt[x],rt[y]);
        }
        else if(a[t1].last()<a[t2].st)
        {
            int tlen=0;
            LL now=a[t1].last()+1;
            for(;t2&&now<a[t2].st;)
            if(now+a[t2].len-1<a[t2].last())
            {
                tlen+=a[t2].len;
                now+=a[t2].len;
                split(rt[y],1,t2,rt[y]);
            }
            else
            {
                int tmp=(a[t2].st-now+1)/2;
                tlen+=tmp;
                a[t2].len-=tmp;a[t2].siz-=tmp;a[t2].st-=tmp;
                break;
            }
            rt[y]=merge(t2,rt[y]);
            int tmpnode=newnode(tlen,1,a[t1].last()+1);
            rt[x]=merge(rt[x],t1);
            rt[x]=merge(rt[x],tmpnode);
            rt[x]=merge(rt[x],rt[y]);
        }
        else
        {
            int tlen=0;
            LL now=a[t2].st+1;
            for(;t1&&now<a[t1].last();)
            if(now+a[t1].len-1<a[t1].st)
            {
                tlen+=a[t1].len;
                now+=a[t1].len;
                split(rt[x],a[rt[x]].cnt-1,rt[x],t1);
            }
            else
            {
                int tmp=(a[t1].last()-now+1)/2;
                tlen+=tmp;
                a[t1].len-=tmp;a[t1].siz-=tmp;
                break;
            }
            rt[x]=merge(rt[x],t1);
            int tmpnode=newnode(tlen,-1,a[t2].st+tlen);
            rt[x]=merge(rt[x],tmpnode);
            rt[x]=merge(rt[x],t2);
            rt[x]=merge(rt[x],rt[y]);
        }
        // printf("%d %d\n",a[rt[x]].siz,a[rt[y]].siz);
        return x;
    }
    void Update(int t,int x)
    {
        if(t==ti[x])return;
        int p=rt[x],tlen=min(a[p].siz,t-ti[x]);
        for(;a[p].l;p=a[p].l);
        long long tmp=a[p].st;
        Cutr(x,tlen);
        rt[x]=merge(newnode(tlen,-1,tmp+t-ti[x]),rt[x]);//printf("%lld %d %lld %d %d\n",tmp,tlen,a[rt[x]].st,a[rt[x]].d,a[rt[x]].siz);
        ti[x]=t;
    }
    void Add(int t,int l,int r)
    {
        // assert(l<=r);
        // printf("ADD %d %d\n",l,r);
        rt[++rc]=newnode(r-l+1,1,1ll<<30);
        ti[rc]=t;
        Segment tmp={l,r,rc};
        auto it=s.lower_bound(tmp);
        if(it!=s.end()&&it->l==r+1)
        {
            Update(t,it->id);
            // printf("*** %d %d %d %d\n",tmp.l,tmp.r,it->l,it->r);
            tmp.id=Merge(tmp.id,it->id);
            tmp.r=it->r;
            s.erase(it);
        }
        it=s.lower_bound(tmp);
        if(it!=s.begin())
        {
            it--;
            if(it->r==l-1)
            {
                Update(t,it->id);
                tmp.id=Merge(it->id,tmp.id);
                tmp.l=it->l;
                s.erase(it);
            }
        }
        s.insert(tmp);
        // printf("%d %d %d\n",tmp.l,tmp.r,a[rt[tmp.id]].siz);
        // printf("ADD %d %d\n",l,r);
    }
    void Del(int t,int l,int r)
    {
        // assert(l<=r);
        // printf("DEL %d %d\n",l,r);
        auto it=s.lower_bound({l,r,0});
        for(;it!=s.end()&&it->r<=r;s.erase(it),it=s.lower_bound({l,r,0}));
        if(it!=s.end()&&it->l<=r)
        {
            Segment tmp=*it;s.erase(it);
            Update(t,tmp.id);
            Cutl(tmp.id,r+1-tmp.l);
            tmp.l=r+1;
            s.insert(tmp);
        }
        it=s.lower_bound({l,r,0});
        if(it!=s.begin())
        {
            it--;
            if(l<=it->r&&it->r<=r)
            {
                Segment tmp=*it;s.erase(it);
                Update(t,tmp.id);
                Cutr(tmp.id,tmp.r-(l-1));
                tmp.r=l-1;
                s.insert(tmp);
            }
            else if(it->r>r)
            {
                Segment tmp=*it;s.erase(it);
                // printf("# %d %d %d %d\n",tmp.l,tmp.r,l,r);
                Update(t,tmp.id);
                Segment tmp2=tmp;
                tmp.r=l-1;tmp2.l=r+1;
                tmp2.id=++rc;ti[rc]=ti[tmp.id];
                Cutlr(tmp.id,tmp2.id,l-tmp.l+1,r-tmp.l+1);
                s.insert(tmp);s.insert(tmp2);
            }
        }
        // printf("DEL %d %d\n",l,r);
    }
    void getSeg(int x,int&l,int &r)
    {
        auto it=s.lower_bound({x,x,0});
        r=it->l-1;
        // assert(it!=s.begin());
        it--;
        l=it->r+1;
        // assert(l<=r);
    }
    LL dfs(int p)
    {
        LL res=a[p].getans();
        if(a[p].l)res=min(res,dfs(a[p].l));
        if(a[p].r)res=min(res,dfs(a[p].r));
        return res;
    }
    LL getans(){return dfs(rt[s.begin()->id]);}
    // void print(int p)
    // {
    //     if(a[p].l)print(a[p].l);
    //     printf("%d %d %lld\n",a[p].len,a[p].d,a[p].st);
    //     if(a[p].r)print(a[p].r);
    // }
}T;
int tree[M<<2],tag[M<<2],n,x;
vector<pair<int,int>>add[M+10],del[M+10];
void modify(int p,int le,int ri,int ll,int rr,int x)
{
    if(ll<=le&&ri<=rr){tag[p]+=x;tree[p]+=x;return;}
    int mid=(le+ri)>>1;
    if(ll<=mid)modify(p<<1,le,mid,ll,rr,x);
    if(rr>mid)modify(p<<1|1,mid+1,ri,ll,rr,x);
    tree[p]=max(tree[p<<1],tree[p<<1|1])+tag[p];
}
int findl(int p,int le,int ri,int ll,int rr,int sum)
{
    if(!(tree[p]+sum))return -1;
    if(le==ri)return le;
    int mid=(le+ri)>>1;
    int res=-1;
    if(ll<=mid)res=findl(p<<1,le,mid,ll,rr,sum+tag[p]);
    if(res==-1&&rr>mid)res=findl(p<<1|1,mid+1,ri,ll,rr,sum+tag[p]);
    return res;
}
int findr(int p,int le,int ri,int ll,int rr,int sum)
{
    if(!(tree[p]+sum))return -1;
    if(le==ri)return le;
    int mid=(le+ri)>>1;
    int res=-1;
    if(rr>mid)res=findr(p<<1|1,mid+1,ri,ll,rr,sum+tag[p]);
    if(res==-1&&ll<=mid)res=findr(p<<1,le,mid,ll,rr,sum+tag[p]);
    return res;
}
int main()
{
    scanf("%d%d",&n,&x);
    rep(i,n)
    {
        int l,r,a,b;
        scanf("%d%d%d%d",&l,&r,&a,&b);
        del[l-1].pb(mp(a,b));
        add[r+1].pb(mp(a,b));
    }
    T.Init(x);
    for(int i=0;i<=M+1;i++)
    {
        for(auto j:add[i])
        {
            modify(1,1,M,j.first,j.second,-1);
            int l,r;
            T.getSeg(j.first,l,r);
            int tmp=findl(1,1,M,l,r,0);
            if(tmp==-1)T.Add(i,j.first,j.second);
            else
            {
                if(tmp>l)T.Add(i,l,tmp-1);
                tmp=findr(1,1,M,l,r,0);
                if(tmp<r)T.Add(i,tmp+1,r);
            }
        }
        // if(i<=11)
        // {
        //     printf("%d:\n",i);
        //     for(auto j:T.s)
        //     {
        //         T.Update(i,j.id);
        //         printf("%d %d %d:\n",T.a[T.rt[j.id]].siz,j.l,j.r);
        //         T.print(T.rt[j.id]);
        //     }
        //     puts("");
        // }
        for(auto j:del[i])modify(1,1,M,j.first,j.second,1),T.Del(i,j.first,j.second);
        // if(i<=11)
        // {
        //     printf("%d:\n",i);
        //     for(auto j:T.s)
        //     {
        //         T.Update(i,j.id);
        //         printf("%d %d %d:\n",T.a[T.rt[j.id]].siz,j.l,j.r);
        //         T.print(T.rt[j.id]);
        //     }
        //     puts("");
        // }
        // assert(T.a[0].siz==0);
    }
    printf("%lld\n",T.getans());
    return 0;
}