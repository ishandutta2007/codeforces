#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;

const ll inf = 1e18 + 1;

ll n, m, k, q[maxn], v[maxn];

set<pair<ll, ll> > s;

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    for (int i = 0; i < m; i++){
        int t, j;
        cin >> t >> j;
        j--;
        if (t == 1){
            if (s.size() < k)
                s.insert(make_pair(q[j], j)), v[j] = 1;
            else
            if (s.begin()->first < q[j])
                v[s.begin()->second] = 0, s.erase(s.begin()), v[j] = 1, s.insert(make_pair(q[j], j));
        }
        else{
            if (v[j])
                cout << "YES";
            else
                cout << "NO";
            cout << '\n';
        }
    }
}