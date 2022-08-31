#include <bits/stdc++.h>
#define f(i,n) for(i=0;i<n;i++)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    int x,y,z,a,b,c;
    cin >> x >> y >> z >> a >> b >> c ;
    
    if(a+b+c< x+y+z) cout << "NO\n";
    else if(a<x) cout << "NO\n";
    else if(a+b-x < y) cout << "NO\n";
    else cout <<"YES";
    
    
    
    
    
    
    return 0;
}