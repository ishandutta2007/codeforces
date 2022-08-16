#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define f(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
    fast;
    
    int n;
    cin >> n;
    if(n==0) cout << 1;
    else if(n%4 == 1) cout << 8;
        else if(n%4==2) cout << 4;
        else if(n%4==3) cout << 2;
        else cout << 6;
}