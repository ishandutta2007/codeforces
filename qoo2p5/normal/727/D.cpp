#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld EPS = 1e-7;

const int M = 6;
const int N = 1e5 + 123;

map<string, int> pp;
map<int, string> rev;
int n;
string ans[N];
int cnt[M];
vector<int> a[M + 1];

int run() {
    pp["S"] = 0;
    pp["M"] = 1;
    pp["L"] = 2;
    pp["XL"] = 3;
    pp["XXL"] = 4;
    pp["XXXL"] = 5;
    
    for (auto &it : pp) {
        rev[it.second] = it.first;
    }
    
    for (int i = 0; i < M; i++) {
        cin >> cnt[i];
    }
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int k = (int) s.size();
        int ind = -1;
        
        for (int j = 0; j < k; j++) {
            if (s[j] == ',') {
                ind = j;
            }
        }
        
        if (ind == -1) {
            ans[i] = s;
            cnt[pp[s]]--;
        } else {
            int id = pp[s.substr(0, ind)];
            a[id].push_back(i);
        }
    }
    
    for (int i = 0; i < M - 1; i++) {
        while (!a[i].empty()) {
            int el = *a[i].rbegin();
            a[i].pop_back();
            
            if (cnt[i] > 0) {
                cnt[i]--;
                ans[el] = rev[i];
            } else {
                cnt[i + 1]--;
                ans[el] = rev[i + 1];
            }
        }
    }
    
    bool ok = true;
    for (int i = 0; i < M; i++) {
        ok &= cnt[i] >= 0;
    }
    
    if (!ok) {
        cout << "NO\n";
        return 0;
    }
    
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return run();
}