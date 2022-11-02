#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

const int INF = 1000000000000000000ll;
const int mod = 1000000007;

struct pyt { 
    int k, pos, id;
    
    bool operator<(const pyt &other) const {
        return k < other.k;
    }
};

int res[1000010];

vector<pyt> pytania;
vector<pair<int, int> > v;
//set<pair<int, int> > s;

const int baza = 1 << 20;
int drz[2 * baza];
int pod[2 * baza];

void add(int gdzie, int co) {
    gdzie += baza;
    pod[gdzie] = co;
    while (gdzie) {
        drz[gdzie]++;
        gdzie /= 2;
    }
}

int czytaj(int co) {
    //cout << " " << drz[1] << " " << co << endl;
    int gdzie = 1;
    while (gdzie < baza) {
        if (drz[gdzie * 2] >= co) {
            gdzie *= 2;
        } else {
            co -= drz[gdzie * 2];
            gdzie = gdzie * 2 + 1;
        }
    }
    //cout << gdzie - baza << endl;
    return pod[gdzie];
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    for (int a, i = 1; i <= n; i++) {
        cin >> a;
        v.push_back({-a, i});
    }
    sort(v.begin(), v.end());
    cin >> m;
    for (int k, p, i = 1; i <= m; i++) {
        cin >> k >> p;
        pytania.push_back({k, p, i});
    }
    sort(pytania.begin(), pytania.end());
    
    int it = 0;
    for (pyt &i : pytania) {
        while (drz[1] < i.k) {
            //s.insert({v[it].second, -v[it].first});
            add(v[it].second, -v[it].first);
            it++;
        }
        
        /*cout << i.k << endl;
        for (auto j : s) {
            cout << j.first << " " << j.second << endl;
        }
        cout << endl;*/
        
        
        //auto x = s.lower_bound(make_pair(i.pos, 0));
        res[i.id] = czytaj(i.pos);
    }
    
    for (int i = 1; i <= m; i++) {
        cout << res[i] << "\n";
    }
    
    return 0;
}