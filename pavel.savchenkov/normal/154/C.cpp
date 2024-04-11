#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define forn(i,n) for (int (i)=0;(i)<(n);i++)
#define pb push_back
#define i64 long long
using namespace std;
vector <int> g[1100000];
int n,m;
i64 h1[1100000];
i64 h2[1100000];
i64 p[1100000];

int main()
{
    cin >> n >> m;
    forn(i,m)
    {
     int u,v; scanf("%d%d",&u,&v); u--; v--;
     g[u].pb(v + 1); g[v].pb(u + 1); 
    }
    p[0] = 1; for (int i=1; i<n; i++) p[i] = p[i-1] * 123454321;
    
    forn(i,n) 
    {
    
     sort(g[i].begin(),g[i].end());
     h2[i] = 0;
     forn(j,(int)g[i].size()) h2[i] += g[i][j]*p[j];
     
     g[i].pb(i+1); 
     sort(g[i].begin(),g[i].end());
     h1[i] = 0;
     forn(j,(int)g[i].size()) h1[i] += g[i][j]*p[j];
     
    }

    sort(h1,h1+n);
    sort(h2,h2+n);
    
    i64 ans = 0;
    i64 j = 1;
    
    forn(i,n)
     if (h1[i] != h1[i+1] || i == n-1) { ans += j*(j-1)/2; j = 1; } else j++;
    
    j = 1;
    
    forn(i,n)
     if (h2[i] != h2[i+1] || i == n-1) { ans += j*(j-1)/2; j = 1; } else j++;
     
    cout << ans << endl;
    return 0;
}