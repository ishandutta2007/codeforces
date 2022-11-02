#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<int> g[n];
    for(int i = 0; i<m; i++){
        int x, y;
        cin >> x >> y;

        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }

    pair<int, int> a[n];
    int b[n];

    for(int i = 0; i<n; i++){
        cin >> a[i].first;
        a[i].second = i;

        b[i] = a[i].first;
    }

    bool flag = 0;

    sort(a, a + n);
    for(int i = 0; i<n; i++){
        int x = a[i].second;
        set<int> s;

        for(int to: g[x]){
            if(b[to] < a[i].first) s.insert(b[to]);
            if(b[to] == a[i].first) flag = 1;
        }

        if(s.size() < a[i].first - 1) flag = 1;
    }

    if(flag){
        cout << -1;
        return 0;
    }

    for(int i = 0; i<n; i++){
        cout << a[i].second + 1 << " ";
    }

}