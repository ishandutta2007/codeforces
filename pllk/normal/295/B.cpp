#include <iostream>

#define ll long long int

using namespace std;

int n;
int t[500][500];
int u[500][500];
int x[500];
ll v[500];
ll s;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> x[n-i-1];
        x[n-i-1]--;
    }
    for (int k = 1; k < n; k++) {
        for (int i = 0; i < k; i++) {
            s += t[x[i]][x[k]];
            u[x[i]][x[k]] = t[x[i]][x[k]];
            s += t[x[k]][x[i]];
            u[x[k]][x[i]] = t[x[k]][x[i]];
        }
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                int m = u[x[k]][x[i]] + u[x[i]][x[j]];
                if (m < u[x[k]][x[j]]) {
                    s -= (u[x[k]][x[j]]-m);
                    u[x[k]][x[j]] = m;
                }
            }
        }
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                int m = u[x[i]][x[j]] + u[x[j]][x[k]];
                if (m < u[x[i]][x[k]]) {
                    s -= (u[x[i]][x[k]]-m);
                    u[x[i]][x[k]] = m;
                }
            }
        }
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                int m = u[x[i]][x[k]] + u[x[k]][x[j]];
                if (m < u[x[i]][x[j]]) {
                    s -= (u[x[i]][x[j]]-m);
                    u[x[i]][x[j]] = m;
                }
            }
        }
        v[k] = s;
    }
    for (int i = 0; i < n; i++) {
        cout << v[n-i-1] << " ";
    }
    cout << endl;
}