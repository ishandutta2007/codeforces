#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;

int v[MAXN + 1], fr[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        fr[v[i]]++;
    }
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
          if(v[i] != v[j] && fr[v[i]] + fr[v[j]] == n && fr[v[i]] == fr[v[j]]) {
              cout << "YES" << endl << v[i] << " " << v[j] << endl;
              return 0;
          }
    cout << "NO";
    //cin.close();
    //cout.close();
    return 0;
}