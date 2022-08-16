#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
fast; 
    
    int n;
    cin >> n;
    int a = 0;
    
    for(int i=0;i<n;i++)
    {
     int x;
        cin >> x;
        a=max(a,x);
    }
    cout << a;
}