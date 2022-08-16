#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = (1LL<<21);
bool valid[N];
int pref[N];

void solve()
{
   int n,k;
    cin >> n >> k;
  
   string s;
    cin >> s;
    
   f(i,n) pref[i] = (s[i] - '0');
   for(int i=1;i<n;i++) pref[i]+=pref[i-1]; 
    
   int cbit = min(21,k); 
   int dif = k - cbit;
    
   int nex = 1;
   while(nex <= n) nex<<=1;
   nex = min(nex,1<<cbit);
   f(i,nex) valid[i] = 0;
    
   
   for(int i=0;i<=n-k;i++)
   {
       if(dif > 0)
       {
           int ss = pref[i+dif-1];
           if(i > 0) ss-=pref[i-1];
           if(ss != dif) continue;
       }
       
       int nums = 0;
       
       f(j,cbit) 
       {
          nums<<=1;   
           if(s[j+i+dif] == '0') nums|=1;
       }
       
       valid[nums] = 1;
   }

   
   for(int i=0;i<nex;i++)
   {
       if(valid[i] == 0)
       {
           cout <<"YES\n";
           
           f(v,dif) cout << 0;
           int num = i;
           f(v,cbit) cout << ((i>>(cbit-v-1)) & 1); 
           cout << '\n';    
           return;
       }
   }
    
   cout <<"NO\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}