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
    int n;
    cin >> n;
    
    int room[10]={0};
    string c;
    cin >> c;
    
    f(i,n)
    {   
        if(c[i]=='L')
        {
            f(j,10) if(room[j] == 0) {room[j]=1; break;}   
        }
        else if(c[i]=='R')
        {
            for(int j=9;j>=0;j--) if(room[j]==0) { room[j] = 1; break; }   
        }
        else room[c[i]-'0'] = 0;
        
    }
    
    f(i,10) cout << room[i]; 
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}