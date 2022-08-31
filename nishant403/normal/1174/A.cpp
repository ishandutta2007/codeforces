#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
    fast;
    int n;
    cin >> n;
    
    int a[2*n];
    set<int> ss;
    
    f(i,2*n)
    {
        cin >> a[i];
        ss.insert(a[i]);
    }
    if(ss.size()==1) {cout << -1; return 0;}
    
    sort(a,a+2*n);
    
    for(int i=0;i<2*n;i++) cout << a[i] << " ";
    
    
    
    
}