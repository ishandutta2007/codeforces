#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n, q;
double sol;
double val[MAXN];
vector <int> v[MAXN];

void obradi (int x) {
    for (int i=0; i<v[x].size(); i++) {
        int sus = v[x] [i];
        double e = 1 - (1 - val[x]) * (1 - val[sus]);
        sol += e/2;
    }
}

void update (int x, double novi) {
    for (int i=0; i<v[x].size(); i++) {
        int sus = v[x] [i];
        double stari_e = 1 - (1 - val[x]) * (1 - val[sus]);
        double novi_e = 1 - (1 - novi) * (1 - val[sus]);
        sol -= stari_e;
        sol += novi_e;
    }
    sol += val[x];
    sol -= novi;
    val[x] = novi;
}

int main () {
    cin >> n;
    for (int i=1; i<=n; i++) {
        scanf("%lf", &val[i]);
        sol -= val[i];
    }
    for (int i=0; i<n-1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a++; b++;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        obradi(i);
    }
    cin >> q;
    for (int i=0; i<q; i++) {
        int x; double v;
        scanf("%d%lf", &x, &v);
        update(x + 1, v);
        printf("%.8f\n", 1.0 + sol);
    }
    return 0;
}