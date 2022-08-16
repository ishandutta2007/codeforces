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
 
const int M = 998244353;
const int N = 503;
 
int n,m;
int dp2[N][N];
int a[N];
 

int get2(int i,int j);
 
 
//segment i through j is yet to be coloured by min element
int get2(int i,int j)
{
    if(i>j) return 1;
    
    if(i==j) return dp2[i][j] = 1;
    
    if(dp2[i][j] != -1) return dp2[i][j];
    
    int mi = 1000;
    int mpos = 1000;
    
    for(int k=i;k<=j;k++) mi = min(mi,a[k]);
    for(int k=i;k<=j;k++) if(a[k] == mi) mpos = k;
    
    //now colour i through j by colour mi no obstacles
        
    int l = i, r = j;
    int mid = mpos;
    
    int ans = 0;
    int t1=0,t2=0;
    
  for(int ii=l;ii<=mid;ii++)
  {
  	t1+=(get2(i,ii-1)*get2(ii,mid-1))%M;
  	t1%=M;
  }
      
  for(int jj=mid;jj<=r;jj++) 
  {
    t2+=(get2(mid+1,jj)*get2(jj+1,j))%M;
    t2%=M;
  }
    
    return dp2[i][j] = (t1*t2)%M;
}
 
void solve()
{
  f(i,N) f(j,N) dp2[i][j] = -1;
     
  cin >> n >> m;  
     
  f(i,n) cin >> a[i];
  
   cout << get2(0,n-1);     
  
}
 
signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}