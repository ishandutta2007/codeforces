#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
fast; 
    string a,b;
    cin >> a >> b;
    for(auto &c : a)
    {
     if(c>='A' && c<='Z') c=c-'A'+'a';   
    }
    
    for(auto &c : b)
    {
     if(c>='A' && c<='Z') c=c-'A'+'a';   
    }
    
    
    if(a > b ) cout << 1;
    else if(a<b) cout << -1;
    else cout << 0;
}