#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const ll INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld EPS = 1e-9;

const int N = 1e5 + 123;
const int L = 'z' - 'a' + 1;

int n, m;
int a[N];
int cnt[L];
vector<int> pos[L];

bool ok[N];

int run() {
    cin >> m;
    string s;
    cin >> s;
    n = (int) s.size();
    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1] - 'a';
        cnt[a[i]]++;
        pos[a[i]].push_back(i);
    }
    
    set<int> q;
    for (int i = 0; i <= n + 1; i++) {
        q.insert(i);
    }
    
    for (int i = L - 1; i >= 0; i--) {
        bool flag = true;
        sort(pos[i].begin(), pos[i].end()); 
        
        for (int p : pos[i]) {
            auto it = q.find(p);
            int prv, nxt;
            --it;
            prv = *it;
            ++it;
            ++it;
            nxt = *it;
                        
            if (nxt - prv <= m) {
                q.erase(p);
                cnt[i]--;
                ok[p] = true;
            } else {
                flag = false;
            }
        }
        
        if (!flag) {
            break;
        }
    }
    
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            cout << ((char) (i + 'a'));
        }
    }
    cout << "\n";
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    return run();
}