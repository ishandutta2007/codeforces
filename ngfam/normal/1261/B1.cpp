#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int bit[N];
int answer[N];
map < int, vector < int > > pos;
vector < pair < int, int > > queries[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("1.inp" ,"r")) freopen("1.inp", "r", stdin);

    int n; cin >> n;

    vector < int > a(n);

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[-a[i]].push_back(i + 1);
    }

    int q; cin >> q;
    for(int i = 0; i < q; ++i) {
        int k, pos; cin >> k >> pos;
        queries[k].push_back(make_pair(pos, i));
    }

    int sz = 0;
    for(auto &p : pos){
        for(int k = sz + 1; k <= sz + p.second.size(); ++k) {
            int w = p.second[k - sz - 1];
            for(int i = w; i < N; i += i & -i) bit[i]++;
            for(auto r : queries[k]) {
                int low = 0, high = n - 1, ans = n;
                while(low <= high) {
                    int mid = (low + high) >> 1;
                    int calc = 0;
                    for(int i = mid; i > 0; i -= i & -i) calc += bit[i];
                    if(calc >= r.first) {
                        ans = mid;
                        high = mid - 1;
                    }
                    else {
                        low = mid + 1;
                    }
                }
                answer[r.second] = a[ans - 1];
            }
        }
        sz += p.second.size();
    }

    for(int i = 0; i < q; ++i) cout << answer[i] << "\n";

    return 0;
}