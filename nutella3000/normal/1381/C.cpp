#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;


vector<deque<int>> c;

struct comp {
    bool operator()(const int& a, const int& b) const{
        if (c[a].size() != c[b].size()) return c[a].size() > c[b].size();
        return c[a].front() > c[b].front();
    }
};

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int n, x, y;
        cin >> n >> x >> y;
        int start_x = x;
        int start_y = y;
        y -= x;


        vector<int> a(n);
        set<int, comp> b;

        //cout << "b " << endl;

        c.clear();
        c.resize(n + 2);

        for(int i = 0;i < n;i++) {
            cin >> a[i];
            c[a[i]].emplace_back(i);
        }
        int free = -1;
        for(int i = 1;i <= n + 1;i++) if (c[i].empty()) free = i;

        for(int i = 1;i <= n + 1;i++) {
            if (c[i].size()) b.emplace(i);
        }

        vector<int> res(n);

        //cout << "res " << endl;

        while(x--) {
            int col = *b.begin();

            b.erase(b.begin());
            int v = c[col].front();
            c[col].pop_front();
            if (c[col].size()) b.emplace(col);

            res[v] = a[v];
        }

        /*cout << "x" << endl;

        for(auto i : b) {
            for(int j : i) cout << j << " ";
            cout << endl;
        }*/

        while(y) {
            if (b.size() <= 1) {
                break;
            }
            if (b.size() == 3 && y == 3) {
                int col1 = *b.begin();
                int col2 = *(++b.begin());
                int col3 = *(++(++b.begin()));
                int v1 = c[col1].front();
                int v2 = c[col2].front();
                int v3 = c[col3].front();
                res[v1] = a[v2];
                res[v2] = a[v3];
                res[v3] = a[v1];
                y = 0;
                break;
            }

            int col1 = *b.begin();
            b.erase(b.begin());
            int col2 = *b.begin();
            b.erase(b.begin());
            int v1 = c[col1].front();
            int v2 = c[col2].front();
            c[col1].pop_front();
            c[col2].pop_front();

            if (c[col1].size()) b.emplace(col1);
            if (c[col2].size()) b.emplace(col2);

            if (y == 1) {
                res[v1] = a[v2];
                y = 0;
                break;
            }
            y -= 2;
            res[v1] = a[v2];
            res[v2] = a[v1];
        }

        //cout << "y" << endl;

        if (y == 0) {
            int q = 0;
            for(int i = 0;i < n;i++) if (res[i] == a[i]) start_x--;
            if (start_x != 0) n /= q;

            multiset<int> temp;
            for(int i = 0;i < n;i++) temp.emplace(a[i]);

            for(int i = 0;i < n;i++) {
                if (temp.count(res[i])) {
                    start_y--;
                    temp.erase(temp.find(res[i]));
                }
            }

            if (start_y != 0) n /= q;
            if (free == -1) n /= q;

            cout << "YES" << endl;
            for(int i = 0;i < n;i++) {
                if (res[i] == 0) cout << free << " ";
                else cout << res[i] << " ";
            }    
            cout << endl;

        }else cout << "NO" << endl;
    }
}