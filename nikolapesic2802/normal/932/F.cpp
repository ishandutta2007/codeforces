#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
struct func{
    int b;
    ll w;
};
ll calc(func x,int a)
{
    return (ll)x.b*a+x.w;
}
vector<vector<func> > leaves;
const int N=1e5+5;
vector<int> a(N),b(N);
vector<vector<int> > graf(N);
func newFunc;
struct node{
    int l,r;
    func f;
    node *left,*right;
    node()
    {
        left=NULL;
        right=NULL;
        f=newFunc;
    }
    void init(int lv=-1*N,int rv=N)
    {
        l=lv;
        r=rv;
    }
    void extend()
    {
        if(!left)
        {
            int m=(l+r)>>1;
            left=new node();
            right=new node();
            left->init(l,m);
            right->init(m,r);
        }
    }
    void add(func x)
    {
        if(f.b==newFunc.b)
        {
            f=x;
            return;
        }
        int m=(l+r)>>1;
        bool lft=calc(x,l)<calc(f,l);
        bool mid=calc(x,m)<calc(f,m);
        if(mid)
            swap(f,x);
        if(r-l==1)
            return;
        extend();
        if(lft!=mid)
            left->add(x);
        else
            right->add(x);
    }
    ll get(int poz)
    {
        if(f.b==newFunc.b)
            return LLONG_MAX;
        if(r-l==1)
            return calc(f,poz);
        int m=(l+r)>>1;
        extend();
        if(poz<m)
            return min(calc(f,poz),left->get(poz));
        else
            return min(calc(f,poz),right->get(poz));
    }
};
vector<node*> lol;
vector<int> index(N);
vector<ll> res(N);
vector<int> degree(N);
int dfs(int tr,int par)
{
    if(index[tr]!=-1)
        return index[tr];
    vector<int> indexes;
    for(auto p:graf[tr])
    {
        if(p!=par)
            indexes.pb(dfs(p,tr));
    }
    int maxx=-1,koji;
    for(auto p:indexes)
    {
        if((int)leaves[p].size()>maxx)
        {
            maxx=leaves[p].size();
            koji=p;
        }
    }
    //printf("%i\n",koji);
    for(auto p:indexes)
    {
        if(p==koji)
            continue;
        for(auto d:leaves[p])
        {
            leaves[koji].pb(d);
            lol[koji]->add(d);
            assert(leaves[koji].size()<N);
        }
    }
    indexes.clear();
    res[tr]=lol[koji]->get(a[tr]);
    func dd;
    dd.b=b[tr];
    dd.w=res[tr];
    leaves[koji].pb(dd);
    lol[koji]->add(dd);
    return koji;
}
int main()
{
    newFunc.b=1e6;
    newFunc.w=0;
    fill(index.begin(),index.end(),-1);
    int n;
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&b[i]);
    }
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%i %i",&x,&y);
        graf[x].pb(y);
        graf[y].pb(x);
        degree[x]++;
        degree[y]++;
    }
    for(int i=2;i<=n;i++)
    {
        if(degree[i]==1)
        {
            res[i]=0;
            index[i]=leaves.size();
            func tr;
            tr.b=b[i];
            tr.w=0;
            node* t=new node();
            t->init();
            t->add(tr);
            vector<func> d;
            d.pb(tr);
            leaves.pb(d);
            lol.pb(t);
        }
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++)
    {
        printf("%lld ",res[i]);
    }
    return 0;
}