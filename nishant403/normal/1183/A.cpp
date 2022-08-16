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

int check(int n)
{
    
    int d = (n%10);
    d+=(n/10)%10;
    d+=(n/100)%10;
    d+=(n/1000)%10;
    
    return d;
}

void solve()
{
int n;
    cin >> n;
    
    while(check(n)%4 !=0)
    {
     n++;
    }
    cout << n;
    
    
}

signed main()
{
    fast;
    solve();
}