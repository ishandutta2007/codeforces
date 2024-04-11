#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> seg;

const ll ofconst = 4e18;

inline bool of(const ll &a, const ll &b) {
    return (ofconst / a <= b);
}

const int sz = 2e5;
int n;
ll k;
ll a[sz], p[sz];
int nxt[sz];

inline ll query(int i, int j) {
    return (i > j ? 0 : p[j] - (i ? p[i - 1] : 0));
}

int main() {
    fast;
    cin >> n >> k;
    foru(i, 0, n) {
        cin >> a[i];
        p[i] = (i ? p[i - 1] : 0) + a[i];
    }
    ll tot = 0;
    int cr = n;
    ford(i, n - 1, 0) {
        nxt[i] = cr;
        if (a[i] != 1)cr = i;
    }
    foru(i, 0, n) {
        ll crmult = 1;
        int ind = i;
        while(ind<n and crmult<ofconst){
            if(of(crmult,a[ind]))break;
            crmult*=a[ind];
            int rem = nxt[ind]-ind;
            ll crsm = query(i, ind);
            if(crmult%k==0 and crmult/k-crsm<rem and crmult/k-crsm>=0)tot++;
            ind=nxt[ind];
        }
    }
    cout << tot;
    return 0;
}