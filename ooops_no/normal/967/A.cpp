#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int h, m;
    cin >> h >> m;
    int l = h * 60 + m + 1;
    if ( l - 1 > b){
        cout << 0 << " " << 0;
        return 0;
    }
    for (int i = 1; i < a; i++){
        cin >> h >> m;
        int now = h * 60 + m - 1;
        if (now - l >= b * 2){
            l += b;
            cout << l / 60 << " " << l % 60 << endl;
            return 0;
        }
        l = now + 2;
    }
    l += b;
    cout << l / 60 << " " << l % 60 << endl;
}