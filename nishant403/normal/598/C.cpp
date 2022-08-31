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
#define all(x) x.begin(),x.end()

bool cmp(pair<pii,int> & a,pair<pii,int> & b)
{
    return atan2(a.F.S,a.F.F) < atan2(b.F.S,b.F.F);
}

#define big __int128_t

pii get(pii a,pii b)
{
    int num = (a.F*b.F) + (a.S*b.S);
    int den = ((a.F*a.F) + (a.S*a.S))*( (b.F*b.F) + (b.S*b.S) );
    int sgn = (num*num);
    if(num < 0) sgn*=-1;
    return {sgn,den};
}

//return a < b
bool better (pii a,pii b)
{
    big A = b.S; A*=a.F;
    big B = b.F; B*=a.S;
    
    return A < B;
}

void solve()
{
   int n;
   cin >> n;
    
   pair<pii,int> a[n];
    f(i,n) cin >> a[i].F.F >> a[i].F.S;
    f(i,n) a[i].S = i;
    
   sort(a,a+n,cmp); 
    
   pii ang = {-2,0};
   int id = 0; 
    
   f(i,n)
   {
       auto val = get(a[i].F,a[(i+1)%n].F);
       
       if(better(ang,val))
       {
           ang = val;
           id = i;
       }
   }
    
   cout << a[id].S + 1 << ' ' << a[(id + 1)%n].S + 1; 
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}