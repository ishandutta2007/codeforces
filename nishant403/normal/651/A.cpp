#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define F first
#define S second
#define Fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f(i,n) for(int i=0;i<n;i++)
#define vi vector<int> 
#define pii pair<int,int>

void solve()
{
    int a,b;
    cin >> a >> b;
    
    int ans = 0;
    int temp =0;
    
    while(a>0 && b>0)
    {
        if(a<b) { if(b==1) break; a++; b-=2; }
        else { if(a==1) break; b++; a-=2; }
        ans++;
    }
    
    cout << ans;
}

signed main()
{
 Fast;
 solve();
}