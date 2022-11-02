#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

const int INF = 1000000000000000000LL;
const int mod = 1000000007;

struct moj {
    int kiedy;
    bool pocz;
    int s, e;
    
    bool operator < (const moj &other) const {
        if (kiedy == other.kiedy) {
            return pocz > other.pocz;
        }
        return kiedy < other.kiedy;
    }
    
    void wypisz() {
        cout << kiedy << " " << pocz << " " << s << " " << e << endl;
    }
};

bool algo(const vector<pair<int, int> > &t1, const vector<pair<int, int> > &t2) {
    multiset<int> s, e;
    vector<moj> v;
    for (int i = 0; i < (int)t1.size(); i++) {
        v.push_back({t1[i].first, true, t2[i].first, t2[i].second});
        v.push_back({t1[i].second, false, t2[i].first, t2[i].second});
    }
    sort(v.begin(), v.end());
    for (moj &i : v) {
        //i.wypisz();
        if (i.pocz) {
            s.insert(i.s);
            e.insert(i.e);
            continue;
        }
        
        if (*s.rbegin() > i.e || i.s > *e.begin()) {
            return false;
        }
        s.erase(s.find(i.s));
        e.erase(e.find(i.e));
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<pair<int, int> > t1, t2;
    int n;
    cin >> n;
    for (int a, b, c, d, i = 1; i <= n; i++) {
        cin >> a >> b >> c >> d;
        t1.push_back({a, b});
        t2.push_back({c, d});
    }
    
    if (algo(t1, t2) && algo(t2, t1)) {
        cout << "YES";
    } else {
        cout << "NO";
    }    
    return 0;
}