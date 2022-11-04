#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

struct Data {
    int w, val;
    bool operator <(const Data &other) const {
        return w < other.w;
    }
};

multiset <Data> mst[MAXN + 1];
multiset <Data> :: iterator it, aux;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, a, b, w;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int ans = 0;
    for(i = 1; i <= m; i++) {
        cin >> a >> b >> w;
        it = mst[a].lower_bound({w, 0});
        int best = 1;
        if(it != mst[a].begin()) {
            it--;
            best = it -> val + 1;
        }
        mst[b].insert({w, best});
        it = mst[b].find({w, best});
        if(it != mst[b].begin()) {
            aux = it;
            aux--;
            if(aux -> val >= best) {
                mst[b].erase(it);
            }
            else {
                it++;
                aux = it;
                while(aux != mst[b].end() && aux -> val <= best) {
                    aux++;
                }
                if(aux != it)
                    mst[b].erase(it, aux);
            }
        }
        else {
            it++;
            aux = it;
            while(aux != mst[b].end() && aux -> val <= best) {
                aux++;
            }
            if(aux != it)
                mst[b].erase(it, aux);
        }
        ans = max(ans, best);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}