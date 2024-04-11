#include <bits/stdc++.h>
#define MAXN 100

using namespace std;

pair <int, int> v[MAXN + 1];
int sol[MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int n, i, w, sum;
    ios::sync_with_stdio(false);
    cin >> n >> w;
    for(i = 1; i <= n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v + 1, v + n + 1);
    sum = 0;
    for(i = 1; i <= n; i++) {
        sol[v[i].second] = (v[i].first + 1) / 2;
        sum += (v[i].first + 1) / 2;
    }
    if(sum > w)
        cout << -1;
    else {
        w -= sum;
        for(i = n; i >= 1 && w > 0; i--) {
            int aux = sol[v[i].second];
            sol[v[i].second] = min(v[i].first, sol[v[i].second] + w);
            w -= (sol[v[i].second] - aux);
        }
        for(i = 1; i <= n; i++)
            cout << sol[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}