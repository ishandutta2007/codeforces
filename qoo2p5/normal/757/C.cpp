#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ll MOD = (ll) 1e9 + 7;

const int N = (int) 1e6 + 123;

int n, m;
int ptr = 2;
int id[N];
ll fact[N];

bool cmp(int i, int j) {
    return id[i] < id[j];
}

void run() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        id[i] = 1;
    }
    
    for (int i = 0; i < n; i++) {
        map<int, int> cnt;
        map<int, vector<int>> q;
        int k;
        cin >> k;
        
        for (int j = 0; j < k; j++) {
            int t;
            cin >> t;
            cnt[t]++;
        }
        
        for (auto &it : cnt) {
            q[it.second].push_back(it.first);
        }
        
        for (auto &it : q) {
            sort(it.second.begin(), it.second.end(), cmp);
            
            for (int j = 0; j < (int) it.second.size(); j++) {
                int t = j;
                
                while (t + 1 < (int) it.second.size() && id[it.second[t + 1]] == id[it.second[t]]) {
                    t++;
                }
                
                for (int w = j; w <= t; w++) {
                    id[it.second[w]] = ptr;
                }
                ptr++;
                
                j = t;
            }
        }
    }
    
    map<int, int> cnt;
    for (int i = 1; i <= m; i++) {
        cnt[id[i]]++;
    }
    
    ll ans = 1;
    
    for (auto &it : cnt) {
        ans = (ans * fact[it.second]) % MOD;
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}