#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
int n,i;
    cin >> n;
int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    
    sort(a,a+n);
    
for(i=0;i<n;i+=2) cout << a[i] << " ";

int x = n-1;
    if(x%2!=1) x--;
 
for(;x>=0;x-=2) cout << a[x] << " ";
    
}