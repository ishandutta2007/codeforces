#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 15+10, MOD = 1e9+7;

const int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

int n, m;
bool g[MAXN][MAXN];


const int BASE = 234;
const int M = 1e9+21;
struct S {
    deque<ar<int, 2>> pos;

    void insert_front(ar<int, 2> c){ pos.push_front(c); }
    void pop_back(){ pos.pop_back(); }
    vector<S> nxt() {
        vector<S> ans;

        int front_i = pos[0][0], front_j = pos[0][1];
        for (int k = 0; k < 4; k++) {
            int new_i = front_i+dx[k], new_j = front_j+dy[k];
            if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= m || !g[new_i][new_j]) continue;
            bool bad = 0;
            for (int j = 0; j < sz(pos)-1 && !bad; j++) {
                if (pos[j] == ar<int, 2>{new_i, new_j}) bad = 1;
            }
            if (bad) continue;

            S new_snake{pos};
            new_snake.insert_front({new_i, new_j});
            new_snake.pop_back();
            ans.push_back(new_snake);
        }
        return ans;
    }
    int hash() {
        int ans = 0;
        for (auto c : pos) {
            int v = c[0]*m+c[1];
            ans = (ll(ans)*BASE+v)%MOD;
        }
        return ans;
    }
};

#include<bits/extc++.h>
struct splitmix64_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

int len = 0;
ar<int, 2> pos[9], goal;

S head;
hash_map<int, int> dist;

queue<S> q;

void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            g[i][j] = (s[j] != '#');
            if ('1' <= s[j] && s[j] <= '9') {
                pos[s[j]-'1'] = {i, j};
                len = max(len, s[j]-'0');
            }
            if (s[j] == '@') goal = {i, j};
        }
    }
    for (int i = len-1; i >= 0; i--) {
        head.insert_front(pos[i]);
    }

    q.push(head); dist[head.hash()] = 0;
    while (sz(q)) {
        auto c = q.front(); q.pop();
        int me_dist = dist[c.hash()];
        if (c.pos[0] == goal) { cout << me_dist << '\n'; return; }

        for (auto nxt : c.nxt()) {
            int h = nxt.hash();
            if (dist.find(h) == dist.end()) {
                dist[h] = me_dist+1;
                q.push(nxt);
            }
        }
    }
    cout << -1 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}