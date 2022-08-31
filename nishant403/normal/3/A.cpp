#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


signed main()
{
    fast;
    string s,t;
    cin >> s >> t;
    
    int sx,sy,tx,ty;
    
    sx = s[0]-'a'; 
    sy = s[1]-'0';

    tx = t[0]-'a';
    ty=t[1]-'0';
    
    cout << max(abs(sx-tx),abs(sy-ty) ) << "\n";
    

    
    while(sx!=tx || sy!=ty)
    {
        if(tx > sx ) {cout << 'R'; sx++;  }  
        else if(tx < sx) {cout << 'L'; sx--; }
        
        if(ty > sy ) {cout << 'U'; sy++;  }  
        else if(ty < sy) {cout << 'D'; sy--; }
        
        cout << "\n";
    }
}