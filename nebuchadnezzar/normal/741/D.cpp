#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);
const int MAXN = 5e5 + 5;
const int ALP = 22, MASK = (1 << ALP) - 1;

    const int MAX_MEM = (int)140 * 1024 * 1024;

    int mpos, max_mpos;
    char memory[MAX_MEM];                        

    inline void * operator new (size_t n) {
      char *res = memory + mpos;
      mpos += n;
      assert(mpos <= MAX_MEM);
      return (void *)res;
    }

    inline void operator delete (void *) { }


struct obj {
    unordered_map<int, int> mp;
    int mask, best, addl;
    
    obj() {
        mask = best = addl = 0;
        mp[0] = 0;
    }
    
    void add(int m, int l) {
        m ^= mask;
        l -= addl;
        if (!mp.count(m) || mp[m] < l) {
            mp[m] = l;
        }
    }

    void upd(int m, int l) {
        m ^= mask;
        l -= addl;
        //cerr << "adding " << m << " " << l << endl;
        for (int i = 0; i < ALP; ++i) {
            int tmp = m ^ (1 << i);
            if (mp.count(tmp)) {
                best = max(best, l + mp[tmp] + addl * 2);
            }
        }
        if (mp.count(m)) {
            //cerr << "found this" << endl;
            best = max(best, l + mp[m] + addl * 2);
        }
    }
};

vector<pii> graph[MAXN];
vector<int> ans;

obj dfs(int v) {
    obj now;
    for (auto to : graph[v]) {
        //cerr << "edge " << " " << to.ff << " " << to.ss << endl;
        auto add = dfs(to.ff);
        add.mask ^= (1 << to.ss);
        add.addl += 1;
        //add.upd();
        //cerr << "v: " << v << " " << add.best << endl;
        if (szof(add.mp) > szof(now.mp)) {
            //cerr << "swap" << endl;
            swap(now, add);
        }
        
        now.best = max(now.best, add.best);
        //cerr << "now " << now.best << " " << now.addl << " " << now.mask << endl;

        /*
        cerr << szof(now.mp) << endl;
        for (auto p : now.mp) {
            cerr << p.ff << " " << p.ss << endl;
        }*/

        for (pii p : add.mp) {
            //cerr << "add " << p.ss + add.addl << " " << (p.ff ^ add.mask) << endl;
            now.upd(p.ff ^ add.mask, p.ss + add.addl);
        }

        for (pii p : add.mp) {
            //cerr << "add " << p.ss + add.addl << " " << (p.ff ^ add.mask) << endl;
            now.add(p.ff ^ add.mask, p.ss + add.addl);
        }
    }

    ans[v] = now.best;
    return now;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 1; i < n; ++i) {
        int v;
        char c;
        scanf("%d %c", &v, &c);
        --v;
        graph[v].puba({i, c - 'a'});
    }

    ans.resize(n);
    dfs(0);

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}