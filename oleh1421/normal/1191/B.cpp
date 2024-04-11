#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a,b,c;cin>>a>>b>>c;
    if (int(a[0])>int(b[0])) swap(a,b);
    if (int(b[0])>int(c[0])) swap(b,c);
    if (int(a[0])>int(b[0])) swap(a,b);
    if (a==b && b==c){
        cout<<0;
    } else if (int(a[0])+1==int(b[0]) && int(b[0])+1==int(c[0]) && a[1]==b[1] && b[1]==c[1]){
        cout<<0;
    } else if (a==b || b==c || a==c){
        cout<<1;
    } else if (int(a[0])+1==int(b[0]) && a[1]==b[1]){
        cout<<1;
    } else if (int(a[0])+2==int(b[0]) && a[1]==b[1]){
        cout<<1;
    }else if(int(a[0])+1==int(c[0]) && a[1]==c[1]){
        cout<<1;
    }else if(int(a[0])+2==int(c[0]) && a[1]==c[1]){
        cout<<1;
    }else if(int(b[0])+1==int(c[0]) && b[1]==c[1]){
        cout<<1;
    }else if(int(b[0])+2==int(c[0]) && b[1]==c[1]){
        cout<<1;
    } else cout<<2;
    return 0;
}
//2 6 -2 -6  2