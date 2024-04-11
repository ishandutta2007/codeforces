#include <bits/stdc++.h>
using namespace std;
map<int,int> mp[200001];
int n,m,i,j,k,t,t1,u,v,a,b,same,diff;
char c; 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (i=1;i<=m;i++)
    {
        cin>>c;
        if ((c=='+'))
        {
            cin>>u>>v>>c;
            if (mp[v][u]==(c-96)) same++;
            else if (mp[v][u]) diff++;
            mp[u][v]=c-96;
        }
        else if (c=='-')
        {
            cin>>u>>v;
            if (mp[v][u]==(mp[u][v])) same--;
            else if (mp[v][u]) diff--;
            mp[u][v]=0;
        }
        else
        {
            cin>>k;
            if (((k%2==0)and(same))or((k%2==1)and(same+diff))) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}