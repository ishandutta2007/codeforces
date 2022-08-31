#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define vi vector<int>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
Fast;    
    
    int n,m,x,y,z;
    cin >> n;
    
    int a[n];
    int pref[n+1];
    int smpref[n+1];

    f(i,n) cin >> a[i];
    
    pref[0] = smpref[0] = 0;
    
    f(i,n) pref[i+1] = pref[i] + a[i];
    
    sort(a,a+n);
        
    f(i,n) smpref[i+1] = smpref[i] + a[i];
    
    cin >> m;
    
    while(m--)
    {
     cin >> x >> y >> z;
         
    if(x==1) cout << pref[z] - pref[y-1] << "\n";   
    else cout << smpref[z] - smpref[y-1] << "\n";       
    }
    
}