#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 2e5;

int v[MAXN + 1], sol[MAXN + 1];
bool viz[MAXN + 1];

multiset <int> mst;
multiset <int> :: iterator it;

int aib[MAXN + 1];

int n;

inline void update(int p) {
    for(int i = p; i <= n; i += lsb(i))
        aib[i]++;
}

inline int query(int p) {
    int ans = 0;
    for(int i = p; i > 0; i -= lsb(i))
        ans += aib[i];
    return ans;
}

vector <int> vec;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, k, j;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int mx = 0;
    for(i = 1; i <= k; i++) {
        cin >> v[i];
        sol[i] = v[i];
        viz[v[i]] = 1;
        update(v[i]);
    }
    int sz = k;
    for(i = 1; i <= k; i++) {
        if(query(v[i]) < v[i]) {
            vec.push_back(v[i]);
        }
    }
    sort(vec.begin(), vec.end());
    int last = 0;
    for(i = 0; i < vec.size(); i++) {
        j = vec[i];
        while(j > last) {
            if(viz[j] == 0)
                sol[++sz] = j;
            j--;
        }
        last = vec[i];
    }
    for(i = n; i > mx; i--) {
        sol[++sz] = i;
    }
    mst.clear();
    memset(aib, 0, sizeof(aib));
    for(i = 1; i <= n; i++) {
        update(sol[i]);
        if(i > 1) {
            it = mst.upper_bound(sol[i]);
            if(it != mst.begin()) {
                it--;
                if(query(*it) < *it) {
                    cout << -1;
                    return 0;
                }
            }
        }
        mst.insert(sol[i]);
    }
    for(i = 1; i <= n; i++) {
        cout << sol[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}