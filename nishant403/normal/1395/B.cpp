#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
    fast;
    
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    
    pair<int,int> skip1 = {x,y};
    pair<int,int> skip2 = {1,y};
    
    cout << x << ' ' << y << '\n';
    cout << 1 << ' ' << y << '\n';
    
    x = y = 1;
    
    for(int i=1;i<=(n*m);i++)
    {
        if( (!(x == skip1.first && y == skip1.second)) &&
            (!(x == skip2.first && y == skip2.second)) )
        {
            
        cout << x << ' ' << y << '\n';
        
        }
        
        if(x % 2 == 1) y++;
        else y--;
        
        if(y > m) x++, y = m;
        else if(y < 1) x++, y = 1;
    }
    
}