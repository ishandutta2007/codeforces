#include <bits/stdc++.h>
#define MAXN 300000

using namespace std;

int p[MAXN + 1];
int pos[MAXN + 1];
int poz[MAXN + 1];
int deq[MAXN + 1];

int main() {
    //fstream cin("B.in");
    //ofstream cout("B.out");
    int i, j, n, m, x, y;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> p[i];
        poz[i] = n + 1;
        pos[p[i]] = i;
    }
    for(i = 1; i <= m; i++) {
        cin >> x >> y;
        if(pos[x] > pos[y])
            swap(x, y);
        poz[x] = min(poz[x], pos[y]);
    }
    int b = 0, e = -1;
    long long ans = 0;
    i = j = 1;
    while(i <= n) {
        if(i > j)
            j = i;
        while(b <= e && deq[b] < i)
            b++;
        if(e < b)
            deq[++e] = j;
        while(j <= n && min(poz[p[j]], poz[p[deq[b]]]) > j) {
            while(e >= b && poz[p[deq[e]]] >= poz[p[j]])
               e--;
            deq[++e] = j;
            j++;
        }
        ans += j - i;
        i++;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}