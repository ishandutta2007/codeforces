#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
fast; 
int n,i,j,k;
    
    cin >> n;
int x = 0;
    while(n)
    {
     if(n%10==7 || n%10==4) x++;
    
        n/=10;
    }
    
    if(x==0) {cout << "NO"; return 0;}
    
    while(x)
    {
        if(x%10==7 || x%10==4) {x/=10; continue; }
        else { cout << "NO"; return 0; }
    }
    
    
    cout << "YES";

}