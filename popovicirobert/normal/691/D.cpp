#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;


int p[MAXN + 1];
int sef[MAXN + 1];

inline int myfind(int x) {
    if(sef[x] == 0)
        return x;
    return sef[x] = myfind(sef[x]);
}

inline void myunion(int x, int y) {
   if(myfind(x) != myfind(y))
       sef[myfind(x)] = myfind(y);
}

vector <int> v[MAXN + 1];
int ind[MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, a, b, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        cin >> p[i];
    for(i = 1; i <= m; i++) {
        cin >> a >> b;
        myunion(a, b);
    }
    for(i = 1; i <= n; i++)
        v[myfind(i)].push_back(p[i]);
    for(i = 1; i <= n; i++)
        sort(v[i].begin(), v[i].end(), greater <int>());
    for(i = 1; i <= n; i++) {
        cout << v[myfind(i)][ind[myfind(i)]] << " ";
        ind[myfind(i)]++;
    }
    //cin.close();
    //cout.close();
    return 0;
}