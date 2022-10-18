#include <cstdio>
#include <iostream>
#include <algorithm>
#include <memory.h>
#define forn(i,n) for (int (i)=0;(i)<(n);i++)
#define pb push_back
#define i64 long long
#define inf 1000000000;
using namespace std;
string s;
int d[110000][300];
bool can[300][300];
int k;

int main()
{
    getline(cin,s);
    cin >> k; scanf("\n");
    memset(can,true,sizeof(can));
    int n = (int)s.length();
    forn(i,n) forn(j,300) d[i][j] = inf;
    
    forn(i,k) 
    { 
     char c1 = getchar(); char c2 = getchar(); 
     can[c1][c2] = can[c2][c1] = false; 
     scanf("\n");
    }
    
    forn(i,n)
    for (int j='a'; j<='z'; j++)
    {
       if (i == 0)
        if (s[i] == j) d[i][j] = 0; else d[i][j] = inf;
       d[i][j] = min(d[i][j],i+1);
       d[i+1][j] = min(d[i+1][j],d[i][j]+1);
       if (can[s[i+1]][j]) d[i+1][s[i+1]] = min(d[i+1][s[i+1]],d[i][j]);
    }
    
    int ans = inf;
    for (int j='a'-1; j<='z'; j++)
     ans = min(ans,d[n-1][j]);
    cout << ans << endl;
    return 0;
}