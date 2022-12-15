#include <bits/stdc++.h>
using namespace std;

double nombres[101][10001];

double cbin[101][101];

int main() {
    int n;
    double x;
    cin >> n >> x;

    nombres[0][0] = 1;

    for(int i = 0;i <= 100;i++) {
        cbin[i][i] = cbin[i][0] = 1.;
        for(int j = 1;j < i;j++) {
            cbin[i][j] = cbin[i - 1][j - 1] + cbin[i - 1][j];
        }
    }

    double s = 0;
    vector<int> ks;
    for(int i = 0;i < n;i++) {
        int k;
        cin >> k;
        ks.push_back(k);
        s += k;
    }

    for(int k : ks) {
        for(int j = n - 1;j >= 0;j--) {
            for(int l = 0;l <= 10000 - k;l++) {
                nombres[j + 1][l + k] += nombres[j][l];
            }
        }
    }

    vector<double> probas;
    probas.push_back(1);

    for(int i = 1;i <= n;i++) {
        probas.push_back(1. / cbin[n][i]);
    }

    double esp = 0;
    for(int j = 0;j <= n;j++) {
        for(int l = 0;l < s;l++) {
            if(nombres[j][l] == 0) continue;

            esp += nombres[j][l] * probas[j] * 
            min((s - l) / (n - j), (n / (double)(n - j) + 1) * x / 2.);
        }
    }

    cout << fixed << setprecision(10) << esp << endl;
    return 0;
}