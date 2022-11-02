#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define int long long

signed main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int q;
    cin >> q;
    string s;
    cin >> s;
    int l = 0, r = 1e18, mid = 0;
    int xd = 0, yd = 0;
    for (int i = 0; i < q; i++){
        if (s[i] == 'U'){
            yd++;
        }
        if (s[i] == 'D'){
            yd--;
        }
        if (s[i] == 'L'){
            xd--;
        }
        if (s[i] == 'R'){
            xd++;
        }
    }
    for (int i = 0; i < 1000; i++){
        int ac = a, bc = b;
        int mid = (l + r) / 2;
        int need = mid / q;
        ac += xd * need;
        bc += yd * need;
        for (int i = 0; i < mid % q; i++){
            if (s[i] == 'U'){
                bc++;
            }
            if (s[i] == 'D'){
                bc--;
            }
            if (s[i] == 'L'){
                ac--;
            }
            if (s[i] == 'R'){
                ac++;
            }
        }
        int S = abs(c - ac) + abs (d - bc);
        if (S > mid){
            l = mid;
        }
        else{
            r = mid;
        }
    }

    if (r == 1e18){
        cout << -1;
    }
    else{
        cout << r;
    }
}