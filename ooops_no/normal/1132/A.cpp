#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a != d){
        cout << 0;
    }
    else{
        if (c > 0 && a == 0){
            cout << 0;
        }
        else{
            cout << 1;
        }
    }
}