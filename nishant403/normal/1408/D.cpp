#include <bits/stdc++.h>
using namespace std;
  
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 1e6 + 10;
const int NN = 1e6 + 100;
int rr[N];
int seg[NN];

void solve()
{
   int n,m;
    cin >> n >> m;
    
   pii r[n];
    f(i,n) cin >> r[i].F >> r[i].S;
    
   pii s[m];
    f(i,m) cin >> s[i].F >> s[i].S;
   
   f(i,N) rr[i] = -1;
 
   f(i,m) rr[s[i].F] = max(rr[s[i].F],s[i].S);
   for(int i=N-2;i>=0;i--) rr[i] = max(rr[i],rr[i+1]); 
 
   vector<pii> go; 
   
   go.pb({0,rr[0]});
    
   for(int i=1;i<N;i++)
       if(rr[i] != rr[i-1]) go.pb({i,rr[i]});
    
   go.pb({NN,NN});
    
   f(i,n) 
   {
       auto idd = upper_bound(go.begin(),go.end(),r[i]) - go.begin();
       
       seg[go[idd].F - r[i].F - 1] = max(seg[go[idd].F - r[i].F - 1] , rr[r[i].F] - r[i].S + 1);
       
       while(idd < (int)go.size()-1)
       {
           seg[go[idd+1].F-1 - r[i].F] = max(seg[go[idd+1].F-1 - r[i].F],go[idd].S - r[i].S + 1); 
           idd++;
       }
   }
   
   int res = 3e6;
    
   for(int i=N-1;i>=0;i--)
   {
       seg[i] = max(seg[i],seg[i+1]);
       res = min(res,i + seg[i]);
   }
    
   cout << res;
}

signed main()
{
    fast;
    solve();
}