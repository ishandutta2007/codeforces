#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()
vector<vector<int> > graf;
const int N=1e5+5;
int max_depth[N];
int visited[N];
int dfs(int tr)
{
    visited[tr]=1;
    for(auto p:graf[tr])
    {
        if(!visited[p])
        {
            //printf("Pozivam %i iz %i\n",p,tr);
            max_depth[tr]=max(max_depth[tr],dfs(p)+1);
        }
    }
    return max_depth[tr];
}
int v2[N];
int ro;
bool check(int tr,int k)
{
    //printf("Proveravam %i %i\n",tr,k);
    v2[tr]=1;
    if(k==0)
    {
        if(tr==ro)
        {
            if(graf[tr].size()>0)
                return false;
            else
                return true;
        }
        else
        {
            if(graf[tr].size()>1)
                return false;
            else
                return true;
        }
    }
    if(tr==ro)
    {
        if(graf[tr].size()<3)
        {
            return false;
        }
    }
    else
    {
        if(graf[tr].size()<4)
        {
            return false;
        }
    }
    bool t=true;
    for(auto p:graf[tr])
    {
        if(!v2[p])
        {
            if(!check(p,k-1))
                t=false;
        }
    }
    return t;
}
int main()
{
    int n,k;
    scanf("%i %i",&n,&k);
    if(k>10)
    {
        printf("No\n");
        return 0;
    }
    graf.resize(n);
    //printf("%i\n",n);
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;
        b--;
        graf[a].pb(b);
        graf[b].pb(a);
    }
    dfs(0);
    int root=-1;
    for(int i=0;i<n;i++)
    {
        if(max_depth[i]==k)
        {
            if(root!=-1)
            {
                printf("No\n");
                return 0;
            }
            else
            {
                root=i;
            }
        }
        //printf("Max:dubina od %i: %i\n",i,max_depth[i]);
    }
    if(root==-1)
    {
        printf("No\n");
        return 0;
    }
    ro=root;
    if(check(root,k))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}