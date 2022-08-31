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
    int n,k;
    cin >> n >> k;
    
    string a1;
    cin >> a1;
    
    string b1;
    
    cout << n << endl;
    
    f(i,k) b1+=a1[i];
    
    int id = 0;
    
    while(b1.length() < n) 
    {
       b1+=a1[id++];
       id%=k;
    }
    
    if(b1 >= a1)
    {
        cout << b1;
        return;
    }
    else 
    {
        int carry = 1;
        
        for(int i=k-1;i>=0;i--)
        {
            int dg = b1[i]-'0';
            dg+=carry;
            b1[i] = (dg%10)+'0';
            carry=dg/10;
        }
        
        for(int i=k;i<n;i++) b1[i] = b1[i%k];
           
        cout << b1;
    }
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}