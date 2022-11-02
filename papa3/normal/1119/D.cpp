#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 5000000000000000000ll

int n;
int tab[1000010];
vector<int> v;

int pref[1000010];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> tab[i];
    }
    sort(tab+1, tab+n+1);
    tab[n+1] = INF;
    for (int i=1; i<=n; i++) {
        v.push_back( tab[i+1]-tab[i] );
    }
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); i++) {
        pref[i+1] = pref[i] + v[i];
        //cout << v[i] << " ";
    }
    //cout << endl;

    /*for (int i=1; i<=n; i++) {
        cout << pref[i] << " ";
    }
    cout << endl;*/

    int q;
    cin >> q;
    int l, r;
    while (q--) {
        cin >> l >> r;
        r -= l;
        r++;

        int pocz=0, kon=n, sr;
        while (kon-pocz > 1) {
            sr = (pocz + kon)/2;
            if (v[sr-1] <= r) {
                pocz = sr;
                //cout << " " << sr << endl;
            }
            else kon = sr;
        }

        //cout <<r << "," << pocz << ":";
        //continue;
        int res = pref[pocz] + (n - pocz)*r;
        cout << res << " ";
    }

    return 0;
}/*
2
1 500000000000000000
2
1000000000000000000 1000000000000000000
0 1000000000000000000
*/