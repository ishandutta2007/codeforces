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

void solve()
{
  int n;
  string a,b;
    
  cin >> n;
  cin >> a;
  cin >> b;
    
  int cn = 0;
  f(i,n) if(a[i] == 'a') cn++;
  f(i,n) if(b[i] == 'a') cn++;
      
  if( (cn % 2) == 1) { cout << -1; return;}
  
  int ans=0;  
  int cn1=0,cn2=0;
    
  vi a1,a2;  
    
  f(i,n) if(a[i] =='a' && b[i]=='b') { cn1++; a1.pb(i+1); }
  f(i,n) if(a[i] =='b' && b[i]=='a') { cn2++; a2.pb(i+1); }
   
  ans = cn1/2;
  ans+=cn2/2;
    
  if( (cn1 % 2) == 1 && (cn2 % 2) == 1) ans+=2;
    
  cout << ans<< "\n";
      
     for(int i=0;i+1<cn1;i+=2) cout << a1[i] <<" " << a1[i+1] << "\n";
 
    
     for(int i=0;i+1<cn2;i+=2) cout << a2[i] <<" " << a2[i+1] << "\n";
 
    
  if( ((cn1%2)==1) && ((cn2%2)==1) )  
  {
    cout << a1[cn1-1] <<" "<<a1[cn1-1]<<"\n";
    cout << a1[cn1-1] <<" "<<a2[cn2-1];  
  }      
}

signed main()
{
    fast;
    solve();
}