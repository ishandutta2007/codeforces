#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int M = 1e9+7;
vector<int> divs[2001];
    
signed main()
{
 fast;
 int n;

 cin >> n ;
    
   int a[n];
    
    for(int i=0;i<n;i++) cin>> a[i];
    
    sort(a,a+n);
    
    int ans = 0;
    
    for(int i=1;i<=n;i++) ans+=abs(a[i-1]-i);
    
    cout << ans;
    
}