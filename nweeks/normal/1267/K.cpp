#include <bits/stdc++.h>
#define int long long
using namespace std;

int coeff[100][100];

int nbPossibles(map<int, int> sign, int nbPlaces) {
    if(sign.empty()) return 1;

    auto it = sign.rbegin();
    int nombre = it->second;
    int val = it->first;
    sign.erase(val);

    if(val == 0) return 1;
    
    if(nbPlaces - val + 1 < 0) return 0;
    if(nombre > nbPlaces - val + 1) return 0;

    return coeff[nbPlaces - val + 1][nombre] * nbPossibles(sign, nbPlaces - nombre);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    coeff[0][0] = 1;
    for(int n = 1;n < 100;n++) {
        coeff[n][0] = 1;
        coeff[n][n] = 1;
        for(int k = 1;k < n;k++) {
            coeff[n][k] = coeff[n - 1][k] + coeff[n - 1][k - 1];
        }
    }

    int nbTests;
    cin >> nbTests;

    for(int iTest = 0;iTest < nbTests;iTest++) {
        int v;
        cin >> v;

        int nbPlaces = 0;

        map<int, int> sign;

        int p = 2;
        while(v != 0) {
            sign[v % p]++;
            v /= p;
            p++;
            nbPlaces++;
        }

        int somme = nbPossibles(sign, nbPlaces);
        if(sign.count(0)) {
            sign[0]--;
            somme -= nbPossibles(sign, nbPlaces - 1);
        }

        cout << somme - 1 << "\n";
    }
    return 0;
}