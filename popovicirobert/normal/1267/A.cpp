#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


using namespace std;

const ll INF = 1e18;

vector <ll> t;

struct Comp {
    int id;
    bool operator <(const Comp &other) const {
        if(t[id] == t[other.id]) return id < other.id;
        return t[id] < t[other.id];
    }
};

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector < pair <ll, int> > evs;
    vector <ll> l(n + 1), r(n + 1);
    t.resize(n + 1);

    for(i = 1; i <= n; i++) {
        cin >> l[i] >> r[i] >> t[i];
        evs.push_back({l[i], i});
        evs.push_back({r[i], -i});
    }

    sort(evs.begin(), evs.end());

    multiset <Comp> mst;
    ll last = INF, ans = 0;

    int pos = 0;
    i = 0;

    while(i < 2 * n) {
        ll curt = INF;
        if(mst.size()) {
            curt = t[mst.begin() -> id];
            ll num = (evs[i].first - last) / curt;
            ans += num, last += num * curt;
        }

        if(evs[i].second < 0) {
            if(mst.find({-evs[i].second}) != mst.end()) {
                mst.erase(mst.find({-evs[i].second}));
            }
            if(mst.empty()) {
                last = INF;
            }
            i++;
        }
        else {
            if(last == INF) {
                last = evs[i].first;
                mst.insert({evs[i++].second});
                continue;
            }

            //cerr << ans << " " << last << " " << evs[i].first << " " << curt << "\n";

            while(mst.size() && last + t[mst.begin() -> id] > r[mst.begin() -> id]) {
                mst.erase(mst.begin());
            }

            ll mn = last + (mst.size() ? t[mst.begin() -> id] : INF);
            pos = max(pos, i);

            while(pos < 2 * n && mn > evs[pos].first) {
                if(evs[pos].second < 0) {
                    if(mst.find({-evs[pos].second}) != mst.end()) {
                        mst.erase(mst.find({-evs[pos].second}));
                    }
                    pos++;
                    continue;
                }

                //cerr << evs[pos].first << " " << t[evs[pos].second] << "  ";
                mn = min(mn, evs[pos].first + t[evs[pos].second]);
                mst.insert({evs[pos++].second});
            }

            //cerr << "\n\n";
            //cerr << mn << " " << found << "\n";

            last = mn;
            ans++;

            i = pos;
        }
    }

    cout << ans;

    return 0;
}