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

const int ssz = 1e3, sz = 1e5;
int n, m;
seg p[sz];
int a[sz], mxp[sz], mxs[sz];

int main() {
    fast;
    int mymn = 1e9;
    cin >> n >> m;
    foru(i, 0, n) {
        cin >> a[i];
        mymn = min(mymn, a[i]);
    }
    foru(i, 0, m) {
        cin >> p[i].first.first >> p[i].first.second;
        p[i].first.first--;
        p[i].first.second--;
        p[i].second=i;
    }
    foru(i, 0, n) {
        if (!i) {
            mxp[i] = a[i];
            mxs[n - i - 1] = a[n - i - 1];
        }
        else {
            mxp[i] = max(mxp[i - 1], a[i]);
            mxs[n - i - 1] = max(mxs[n - i], a[n - i - 1]);
        }
    }
    int bst = mxp[n - 1] - mymn;
    vector<int> bv;
    foru(i, 0, n) {
        vector<pii> l, r;
        foru(j, 0, m) {
            if (p[j].first.first <= i and p[j].first.second >= i) {
                l.pb({p[j].first.first,p[j].second});
                r.pb({p[j].first.second,p[j].second});
            }
        }
        int inamt = l.size(),upto=-1;
        sort(l.rbegin(), l.rend());
        sort(r.begin(), r.end());
        foru(j, 0, inamt) {
            if(l[j].first == 0)break;
            int cand = mxp[l[j].first-1]-(a[i]-(j+1));
            if(cand>bst){
                bst=cand;
                upto=j;
            }
        }
        if(upto!=-1){
            bv.clear();
            foru(j,0,upto+1)bv.pb(p[l[j].second].second);
        }
        upto=-1;
        foru(j, 0, inamt) {
            if(r[j].first == n-1)break;
            int cand = mxs[r[j].first+1]-(a[i]-(j+1));
            if(cand>bst){
                bst=cand;
                upto=j;
            }
        }
        if(upto!=-1){
            bv.clear();
            foru(j,0,upto+1)bv.pb(p[r[j].second].second);
        }
    }
    cout << bst << '\n' << bv.size() << '\n';
    for (int x : bv)cout << x + 1 << ' ';
    return 0;
}