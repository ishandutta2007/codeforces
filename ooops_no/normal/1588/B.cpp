#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

int ask(int l, int r){
    cout << "? " << l << ' ' << r << endl;
    int p;
    cin >> p;
    return p;
}

void ans(int i, int j, int k){
    cout << "! " << i << ' ' << j << ' ' << k << endl;
    return;
}

int get(int v){
    int l = 0, r = 1e9;
    while(r - l > 1){
        int mid = (r + l) / 2;
        if (mid * (mid - 1) / 2 <= v){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return l;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt = ask(1, n);
        int l = 0, r = n + 1;
        while(r - l > 1){
            int mid = (r + l) / 2;
            if (ask(mid, n) == cnt){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        int dl = cnt - ask(l + 1, n) + 1;
        ans(l, l + dl, l + dl + get(cnt - dl * (dl - 1) / 2) - 1);
    }
    return 0;
}