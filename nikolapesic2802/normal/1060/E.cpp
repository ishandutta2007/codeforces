#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
vector<vector<int> > graf;
vector<int> subtree,dubina;
void dfs(int tr,int par)
{
    subtree[tr]=1;
    for(int i=0;i<graf[tr].size();i++)
    {
        int sl=graf[tr][i];
        if(sl==par)
            continue;
        dubina[sl]=dubina[tr]+1;
        dfs(sl,tr);
        subtree[tr]+=subtree[sl];
    }
}
int main()
{
    int n;
    scanf("%i",&n);
    graf.resize(n+1);
    subtree.resize(n+1);
    dubina.resize(n+1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        graf[a].pb(b);
        graf[b].pb(a);
    }
    dfs(1,-1);
    ll res=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        res+=(ll)subtree[i]*(ll)(n-subtree[i]);
        if(dubina[i]%2==0)
        {
            cnt++;
        }
    }
    res+=(ll)cnt*(ll)(n-cnt);
    printf("%lld\n",res/2);
    return 0;
}