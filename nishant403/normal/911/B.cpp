#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
int n,a,b,i;
    
int ans = 0;
    cin >> n >> a >> b;
    
    
int low =1 , high =n-1;
   
if(n>a) high = a;
if(n>b) low = n-b;
    
for(i = low ; i <= high ;i++)
    ans=max(ans,min(a/i,b/(n-i) ) );
    
cout << ans;    
}