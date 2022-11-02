#include <bits/stdc++.h>
using namespace std;

const long long M = 1e9 + 7;

struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> m >> n;

    dsu DSU = dsu(n + 1);

    vector<int> ans;
    int comp[n];
    vector<int> vert[n];
    bool ok[n];

    for(int i = 0; i<n; i++){
        comp[i] = i;
        vert[i].push_back(i);
        ok[i] = 0;
    }

    for(int i = 0; i<m; i++){
        int c;
        cin >> c;

        if(c == 1){
            int x;
            cin >> x;
            /*
            if(ok[comp[x - 1]] == 0) ans.push_back(i + 1);
            ok[comp[x - 1]] = 1;
            */

            if(!DSU.same(x - 1, n)) ans.push_back(i + 1);
            DSU.merge(x - 1, n);
        }

        else{
            int x, y;
            cin >> x >> y;
            x--;
            y--;

            if(!DSU.same(x, y)) ans.push_back(i + 1);
            DSU.merge(x, y);

            /*
            if(comp[x] != comp[y]){
                if(!ok[comp[x]] || !ok[comp[y]]) ans.push_back(i + 1);

                if(vert[comp[x]].size() <= vert[comp[y]].size()){
                    for(int v: vert[comp[x]]){
                        vert[comp[y]].push_back(v);
                        comp[v] = comp[y];
                    }

                    if(ok[comp[x]] || ok[comp[y]]) ok[comp[y]] = 1;
                    vert[comp[x]].clear();
                }

                else{
                    for(int v: vert[comp[y]]){
                        vert[comp[x]].push_back(v);
                        comp[v] = comp[x];
                    }

                    if(ok[comp[x]] || ok[comp[y]]) ok[comp[x]] = 1;
                    vert[comp[y]].clear();
                }

            }
            */
        }
    }

    long long two = 1;
    for(int i = 0; i<ans.size(); i++){
        two = (2*two) % M;
    }

    cout << two << " " << ans.size() << endl;
    for(auto x: ans){
        cout << x << " ";
    }
}