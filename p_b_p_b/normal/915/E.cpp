#include<bits/stdc++.h>
namespace my_std{
    using namespace std;
    #define pli pair<ll,int>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (int i=(x);i<=(y);i++)
    #define drep(i,x,y) for (int i=(x);i>=(y);i--)
    #define go(x) for (int i=head[x];i;i=edge[i].nxt)
    #define sz 101010
    typedef long long ll;
    template<typename T>
    inline void read(T& t)
    {
        t=0;char f=0,ch=getchar();
        double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
        if(ch=='.')
        {
            ch=getchar();
            while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();
        }
        t=(f?-t:t);
    }
    template<typename T,typename... Args>
    inline void read(T& t,Args&... args){read(t); read(args...);}
    void file()
    {
        #ifndef ONLINE_JUDGE
        freopen("a.txt","r",stdin);
        #endif
    }
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n;

struct miafi
{
    int l,r;
    mutable int v;
    const bool operator < (const miafi &a) const {return l<a.l;}
    miafi(int L,int R,ll V){l=L,r=R,v=V;}
};

set<miafi>s;
int sum;
#define iter set<miafi>::iterator

iter split(int pos)
{
    iter i=s.lower_bound(miafi(pos,0,0));
    if (i!=s.end()&&i->l==pos) return i;
    --i;
    int L=i->l,R=i->r,V=i->v;
    s.erase(i);
    s.insert(miafi(L,pos-1,V));
    return s.insert(miafi(pos,R,V)).fir;
}
void assign(int l,int r,int v)
{
    iter R=split(r+1),L=split(l);
    sum+=v*(r-l+1);
    for (iter i=L;i!=R;++i) sum-=(i->v)*((i->r)-(i->l)+1);
    s.erase(L,R);
    s.insert(miafi(l,r,v));
}

int main()
{
    file();
    int x,y,z,Q;
    read(n,Q);
    sum=n;s.insert(miafi(1,n,1));
    while (Q--)
    {
        read(x,y,z);
        assign(x,y,z-1);
        printf("%d\n",sum);
    }
    return 0;
}