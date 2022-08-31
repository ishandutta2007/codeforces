#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
fast; 
    int n,m;
    string a;
    
    cin >> n >> m;
    
    for(int i=1;i<n-m;i++) cout << i << " " ;
    for(int i=n;i>=n-m;i--) cout << i << " " ;
    
}