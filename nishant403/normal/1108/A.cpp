#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a==b)
    {
     if(c==a) cout << a << " " << d << "\n";
     else cout << a << " " << c << "\n";
    }
    else if(c==d)
    {
        if(a==c) cout << b << " " << c << "\n";
        else cout << a << " " <<  c << "\n";
    }
    else if(a!=c) cout << a << " " << c << "\n";
    else cout << a << " " << d << "\n";
    
    }    
    return 0;
}