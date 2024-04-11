#include <bits/stdc++.h>

using namespace std;
long long k, v, m, n;
long long be[100001];
long long ki[100001];
long long p[100001];
long long mini=1;
int main()
{
    cin >> k >> v >> m >> n;
    for (int i=1; i<=n; i++) {
        cin >> be[i];
    }
    ki[0]=k-1;
    for (int i=1; i<=n; i++) {
        ki[i]=max(ki[i-1]+m, be[i]+m-1);
    }
    if (be[1]>k) {
        cout << k << endl;
        return 0;
    }
    if (ki[n]<v-m) {
        cout << v-m;
        return 0;
    }
    for (int i=1; i<=n; i++) {
        p[i]=ki[i-1]-be[i];
    }
    for (int i=1; i<=n; i++) {
        if (p[i]<p[mini] && ki[i-1]<v-1) {
            mini=i;
        }
    }
    cout << be[mini]-1 << endl;

    return 0;
}