#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 3e5 + 100;
int n;

int st[N+N];
int st2[N+N];

int fun(int a,int b)
{
 return min(a,b);   
}
 
void build()
{
 for(int i=1;i<2*n;i++) st[i] = st2[i] = N; 
}
 
void u1(int id,int val)
{
  for(st[id+=n]=val;id>1;id>>=1)
      st[id>>1] =fun( st[id],st[id^1] );
}
 
int q1(int l,int r)
{
    int res = N;
    
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
     if(l&1) res=fun(res,st[l++]);
     if(r&1) res=fun(res,st[--r]);   
    }
    
    return res;
}

void u2(int id,int val)
{
  for(st2[id+=n]=val;id>1;id>>=1)
      st2[id>>1] =fun( st2[id],st2[id^1] );
}
 
int q2(int l,int r)
{
    int res = N;
    
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
     if(l&1) res=fun(res,st2[l++]);
     if(r&1) res=fun(res,st2[--r]);   
    }
    
    return res;
}

void solve()
{
    cin >> n;
   
    build();
    
   int a[n];
    f(i,n) cin >> a[i];
    
   vi dp(n,0);
   f(i,n) dp[i] = i;
    
   vector<pii> mx,mn; 
    mx.pb({a[0],0});
    mn.pb({a[0],0});
    
    u1(0,0);
    u2(0,0);
    
    for(int i=1;i<n;i++)
    {   
        //find answer from mx
        int l = 0;
        int r = (int)mx.size()-1;
        int res = r+1;
        
        while(l <= r)
        {
            int mid = (l+r)/2;
            
            if(mx[mid].F < a[i])
            {
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        
        if(res > 0) res--;
        dp[i] = min(dp[i],q1(res,(int)mx.size()) + 1);
        
        //find answer from mn
        l = 0;
        r = (int)mn.size()-1;
        res = r+1;
        
        while(l <= r)
        {
            int mid = (l+r)/2;
            
            if(mn[mid].F > a[i])
            {
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        
        if(res > 0) res--;
        
        dp[i] = min(dp[i],q2(res,(int)mn.size()) + 1);
        
        //update mx 
        while(mx.size() > 0 && a[i] >= mx.back().F) mx.pop_back();
        mx.pb({a[i],dp[i]});
        
        u1((int)mx.size()-1,dp[i]);
        
        //update mx 
        while(mn.size() > 0 && a[i] <= mn.back().F) mn.pop_back();
        mn.pb({a[i],dp[i]});
       
        u2((int)mn.size()-1,dp[i]);
    }
    
   cout << dp[n-1]; 
}

signed main()
{
    fast;
    solve();
}