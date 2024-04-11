#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()
const int N=2*1e5+5;
int n;
vector<vector<int> > graf(N);
vector<int> lazy(4*N),num(4*N),minn(4*N);
map<pair<int,int>,int> mapa;
void add(int qs,int qe,int d,int i=1,int l=1,int r=n)
{
    if(r<qs||l>qe){
        if(num[i]==0)
            num[i]=r-l+1;
        return;
    }
    if(qs<=l&&r<=qe)
    {
        lazy[i]+=d;
        if(num[i]==0)
            num[i]=r-l+1;
        return;
    }
    lazy[2*i]+=lazy[i];
    lazy[2*i+1]+=lazy[i];
    lazy[i]=0;
    int mid=(l+r)/2;
    add(qs,qe,d,2*i,l,mid);
    add(qs,qe,d,2*i+1,mid+1,r);
    if(minn[2*i]+lazy[2*i]<minn[2*i+1]+lazy[2*i+1])
    {
        minn[i]=minn[2*i]+lazy[2*i];
        num[i]=num[2*i];
    }
    if(minn[2*i]+lazy[2*i]>minn[2*i+1]+lazy[2*i+1])
    {
        minn[i]=minn[2*i+1]+lazy[2*i+1];
        num[i]=num[2*i+1];
    }
    if(minn[2*i]+lazy[2*i]==minn[2*i+1]+lazy[2*i+1])
    {
        minn[i]=minn[2*i]+lazy[2*i];
        num[i]=num[2*i]+num[2*i+1];
    }
}
int cnt()
{
    if(minn[1]+lazy[1]==0)
        return num[1];
    return 0;
}
vector<int> in(N),out(N),depth(N);
int up[N][20];
int t=0;
void dfs(int tr,int par)
{
    up[tr][0]=par;
    in[tr]=++t;
    for(auto p:graf[tr])
        if(p!=par){
            depth[p]=depth[tr]+1;
            dfs(p,tr);
        }
    out[tr]=t;
}
int lca(int a,int b)
{
    if(depth[a]<depth[b])
        swap(a,b);
    for(int i=19;i>=0;i--)
    {
        if(depth[a]-depth[b]-1>=(1<<i))
        {
            a=up[a][i];
        }
    }
    if(up[a][0]!=b)
        return 0;
    return a;

}
int main()
{
    int q;
    scanf("%i %i",&n,&q);
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        graf[a].pb(b);
        graf[b].pb(a);
    }
    dfs(1,-1);
    for(int j=1;j<20;j++)
    {
        for(int i=1;i<=n;i++)
        {
            int mid=up[i][j-1];
            if(mid==-1)
                up[i][j]=-1;
            else
                up[i][j]=up[mid][j-1];
            //printf("Up[%i][%i]: %i\n",i,j,up[i][j]);
        }
    }
    for(int i=0;i<q;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        if(a>b)
            swap(a,b);
        if(!mapa[{a,b}])
        {
            mapa[{a,b}]=1;
            if(lca(a,b))
            {
                if(depth[a]>depth[b])
                    swap(a,b);
                add(in[lca(a,b)],out[lca(a,b)],1);
                add(in[b],out[b],-1);
                //printf("Zajedno!\n");
            }
            else
            {
                add(1,n,1);
                add(in[a],out[a],-1);
                add(in[b],out[b],-1);
            }
        }
        else
        {
            mapa[{a,b}]=0;
            if(lca(a,b))
            {
                if(depth[a]>depth[b])
                    swap(a,b);
                add(in[lca(a,b)],out[lca(a,b)],-1);
                add(in[b],out[b],1);
                //printf("Zajedno!\n");
            }
            else
            {
                add(1,n,-1);
                add(in[a],out[a],1);
                add(in[b],out[b],1);
            }
        }
        printf("%i\n",cnt());
    }
    return 0;
}