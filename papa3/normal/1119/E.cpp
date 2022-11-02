#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 5000000000000000000ll

int tab[10000010];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >>  n;
    int wolne = 0;
    int res=0;
    for (int a, i=1; i<=n; i++) {
        cin >> a;
        int t = a/2;
        wolne += a%2;

        int x = min(wolne, t);
        res += x;
        wolne-=x;
        t-=x;

        t *= 2;
        x = t/3;
        res += x;
        t -= x*3;
        wolne += t;
    }

    cout << res;
    /*int wolne = 0;
    int n;
    cin >> n;
    int suma=0;
    for (int a, i=1; i<=n; i++) {
        cin >> a;
        tab[i] = a/2;
        suma += tab[i]*2;
        wolne += a%2;
    }

    int res=0;
    int biore = 0;
    for (int i=n; i>0; i--) {
        if (tab[i] == 0) continue;
        if (biore == 1) {
            tab[i]--;
            wolne++;
            suma--;
        } else if (biore == 2) {
            tab[i]--;
        }
        suma -= tab[i]*2;
        int x = min(tab[i], wolne);
        res += x;
        tab[i] -= x;
        wolne -= x;

        if (tab[i] == 0) continue;
        tab[i]*=2;
        while (tab[i] && tab[i]%3 && suma) {
            suma--;
            biore++;
            tab[i] -= 2;
            res++;
        }
        res += tab[i]/3;
    }
    cout << res;*/

    return 0;
}/*
2
1 500000000000000000
2
1000000000000000000 1000000000000000000
0 1000000000000000000
*/