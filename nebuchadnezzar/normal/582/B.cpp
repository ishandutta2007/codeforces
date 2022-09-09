#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long ll;
typedef double dbl;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int n, t;
vector <int> v;

map <int, int> have;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    scanf("%d%d", &n, &t);

    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        v.puba(num);
    }

    if (n * t <= 1e5) {
        vector <int> v2;
        for (int i = 0; i < t; ++i) {
            for (int j = 0; j < n; ++j) {
                v2.puba(v[j]);
            }
        }

        for (int i = 0; i < szof(v2); ++i) {
            int now = 0;
            for (map <int, int>::iterator it = have.begin(); it != have.end(); ++it) {
                if (it -> ff <= v2[i]) {
                    now = max(now, it -> ss);
                }
            }
            ++now;
            have[v2[i]] = max(have[v2[i]], now);
        }
        int ans = 0;
        for (map <int, int>::iterator it = have.begin(); it != have.end(); ++it) {
            ans = max(ans, it -> ss);
        }
        cout << ans << endl;
        return 0;
    }

    
    vector <int> v2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            v2.puba(v[j]);
        }
    }

    for (int i = 0; i < szof(v2); ++i) {
        //cerr << "i: " << i << endl;
        int now = 0;
        for (map <int, int>::iterator it = have.begin(); it != have.end(); ++it) {
            if (it -> ff <= v2[i]) {
                now = max(now, it -> ss);
            }
        }
        //cerr << v2[i] << " " << now << endl;
        ++now;
        have[v2[i]] = max(have[v2[i]], now);
    }
   
    map <int, int> mem = have;
    have.clear();

    reverse(bend(v2));

    for (int i = 0; i < szof(v2); ++i) {
        int now = 0;
        for (map <int, int>::iterator it = have.begin(); it != have.end(); ++it) {
            if (it -> ff >= v2[i]) {
                now = max(now, it -> ss);
            }
        }
        //cerr << v2[i] << " " << now << endl;
        ++now;
        have[v2[i]] = max(have[v2[i]], now);
    }

    map <int, int> inp;

    for (int i = 0; i < n; ++i) {
        inp[v[i]]++;
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        //cerr << v[i] << " " << have[v[i]] << " " << mem[v[i]] << endl;
        ans = max(ans, have[v[i]] + mem[v[i]] +  inp[v[i]] * (t - n - n));
    }

    cout << ans << endl;
    return 0;
}