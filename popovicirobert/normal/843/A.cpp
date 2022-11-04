#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = (int) 1e5;

pair <int, int> v[MAXN + 1];
int p[MAXN + 1];

bool viz[MAXN + 1];

vector <int> sol[MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v + 1, v + n + 1);
    for(i = 1; i <= n; i++)
        p[v[i].second] = i;
    int ans = 0;
    for(i = 1; i <= n; i++) {
        int pos = i;
        if(viz[pos] == 0)
            ans++;
        while(viz[pos] == 0) {
            viz[pos] = 1;
            sol[ans].push_back(pos);
            pos = p[pos];
        }
    }
    cout << ans << endl;
    for(i = 1; i <= ans; i++) {
        cout << sol[i].size() << " ";
        for(auto it : sol[i])
            cout << it << " ";
        cout << endl;
    }
    //cin.close();
    //cout.close();
    return 0;
}