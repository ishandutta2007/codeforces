#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back

const int MAXN = 200005;
const int MOD = 1e9 + 7;

class BIT {
    vector<pll> arr;
    int size;
    public:
    BIT(int sz) : size(sz), arr(sz+1) {}
    void insert(int i, pll v) {
        i++;
        while(i <= size) {
            arr[i].f = (arr[i].f + v.f) % MOD;
            arr[i].s = (arr[i].s + v.s) % MOD;
            i += i & -i;
        }
    }
    pll get(int i) {
        i++;
        pll res = {0,0};
        while(i > 0) {
            res.f = (arr[i].f + res.f) % MOD;
            res.s = (arr[i].s + res.s) % MOD;
            i -= i & -i;
        }
        return res;
    }
    pll range(int i, int j) {
        pll p1 = get(i-1);
        pll p2 = get(j-1);
        return {((p2.f - p1.f) % MOD + MOD) % MOD, ((p2.s - p1.s) % MOD + MOD) % MOD};
    }
};

int main() {
    int asdf; cin >> asdf;
    while(asdf--) {
        int n; cin >> n;
        vector<pii> arr;
        F0R(i, n) {
            int a; cin >> a;
            arr.pb({a, -i});
        }

        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());

        BIT b1(n);

        int rightmost = -1;
        int i = 0;

        ll ans = 0;

        map<int, int> m;

        while(i < n) {
            int ni = i;
            while(ni < n && -arr[ni].s < rightmost) ni++;

            vector<int> v;
            FOR(j, i, ni) {
                pll res = b1.range(-arr[j].s, rightmost);
                b1.insert(-arr[j].s, {res.f + 1, (res.f + res.s + 1) % MOD});
                ans = (ans + res.f + res.s + 1) % MOD;
                
                v.pb(-arr[j].s);
            }

            sort(v.begin(), v.end());
            FOR(j, i, ni)
                m[v[j-i]] = j-i;


            BIT b2(ni-i);
            FOR(j, i, ni) {
                pll res = b2.range(m[-arr[j].s], ni-i);
                
                b1.insert(-arr[j].s, {res.f + 1, res.s});
                b2.insert(m[-arr[j].s], {res.f + 1, res.s});
                ans = (ans + res.s) % MOD;
            }

            if(ni != n) {
                b1.insert(-arr[ni].s, {1,0});
                rightmost = -arr[ni].s;
            }
            i = ni+1;
        }

        cout << (ans % MOD + MOD) % MOD  << endl;
    }
}