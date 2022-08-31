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
 int n,l,r;
    
    cin >> n >> l >> r;
    
    int a1=0,a2=0;
    
    int temp = 1;
    
    int a[n];
    
    f(i,n) a[i] = 1;
    
    for(int i=1;i<l;i++)
    {
        temp = temp*2;
        a[i] = temp;
    }
    
    f(i,n) a1+=a[i];
    
    cout << a1 << " ";
    
    f(i,n) a[i] = 1;
    temp = 1;
    
    for(int i=1;i<r;i++)
    {
     temp=temp*2;
     a[i] = temp;
    }
    
    for(int i=r;i<n;i++) a[i] = a[i-1];
    
    f(i,n) a2+=a[i];
    
    cout << a2;
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}