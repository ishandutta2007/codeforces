#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()
const int N=1e5+5;
vector<vector<int> > graf;
int up[N][20];
int lg[N];
vector<int> depth(N);
void dfs(int tr,int par)
{
    //printf("usao za %i %i\n",tr,par);
    for(auto p:graf[tr])
    {
        if(p==par)
            continue;
        depth[p]=depth[tr]+1;
        dfs(p,tr);
    }
}
int gcd(int a,int b)
{
    if(depth[a]<depth[b])
        swap(a,b);
    for(int j=19;j>=0;j--)
    {
        if(depth[a]-depth[b]>=1<<j)
        {
            a=up[a][j];
        }
    }
    if(a==b)
        return a;
    for(int j=19;j>=0;j--)
    {
        if(up[a][j]!=up[b][j])
        {
            a=up[a][j];
            b=up[b][j];
        }
    }
    return up[a][0];
}
int sparce[N][20];
int nadji2(int l,int r)
{
    if(r-l<0)
        return -1;
    int res=-1;
    int d=r-l+1;
    int tr=l;
    for(int j=20;j>=0;j--)
    {
        if((1<<j)<=d)
        {
            //printf("Usao za %i %i: %i\n",tr,j,sparce[tr][j]);
            if(res==-1)
                res=sparce[tr][j];
            else
                res=gcd(res,sparce[tr][j]);
            tr+=(1<<j);
            d-=(1<<j);
        }
    }
    return res;
}
int nadji(int l,int r)
{
    if(r-l<0)
        return -1;
    if(l==r)
        return l;
    int d=r-l+1;
    //printf("%i %i, %i %i\n",l,lg[d],r-(1<<lg[d])+1,lg[d]);
    int res=gcd(sparce[l][lg[d]],sparce[r-(1<<lg[d])+1][lg[d]]);
    return res;
}
int main()
{
    lg[1]=0;
    for(int i=2;i<N;i++){
        lg[i]=lg[i>>1]+1;
        //printf("log of %i: %i\n",i,lg[i]);
    }
    int n,q;
    scanf("%i %i",&n,&q);
    depth[1]=0;
    graf.resize(n+10);
    up[1][0]=-1;
    for(int i=2;i<=n;i++)
    {
        int a;
        scanf("%i",&a);
        graf[a].pb(i);
        graf[i].pb(a);
        //printf("Iz %i u %i\n",i,a);
        up[i][0]=a;
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
        }
    }
    //printf("zavrsdio!\n");
    for(int i=1;i<=n;i++)
        sparce[i][0]=i;
    for(int j=1;j<20;j++)
    {
        for(int i=1;i<=n;i++)
        {
            int nxt=i+(1<<(j-1));
            //printf("Next: %i\n",nxt);
            if(nxt>n)
                sparce[i][j]=sparce[i][j-1];
            else
                sparce[i][j]=gcd(sparce[i][j-1],sparce[nxt][j-1]);
            //printf("%i %i: %i\n",i,j,sparce[i][j]);
        }
    }
    //printf("sparr");
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%i %i",&l,&r);
        int sl=l,sr=r;
        int d=nadji(l,r);
        //printf("%i %i\n",d,nadji2(l,r));
        int lo=l,hi=r;
        while(lo<hi)
        {
            int mid=(lo+hi)/2;
            int d1=nadji(l,mid);
            if(d1==d)
            {
                hi=mid;
            }
            else
            {
                lo=mid+1;
            }
        }
        //printf("PRvo %i\n",hi);
        int e1=hi;
        int n1=nadji(l,hi-1);
        int n2=nadji(hi+1,r);
        int r1;
        if(n1!=-1&&n2!=-1)
            r1=gcd(n1,n2);
        if(n1==-1)
            r1=n2;
        if(n2==-1)
            r1=n1;
        assert(r1!=-1);
        lo=l,hi=r;
        while(lo<hi)
        {
            int mid=(lo+hi+1)/2;
            int d1=nadji(mid,r);
            if(d1==d)
            {
                lo=mid;
            }
            else
            {
                hi=mid-1;
            }
        }
        //printf("Drugo!%i\n",lo);
        n1=nadji(l,hi-1);
        n2=nadji(hi+1,r);
        int r2;
        if(n1!=-1&&n2!=-1)
            r2=gcd(n1,n2);
        if(n1==-1)
            r2=n2;
        if(n2==-1)
            r2=n1;
        if(depth[r1]<depth[r2])
        {
            printf("%i %i\n",lo,depth[r2]);
        }
        else
        {
            printf("%i %i\n",e1,depth[r1]);
        }
    }
    return 0;
}