#include <cstdio>
#include <iostream>

using namespace std;
struct op {
    int t, l, r, dop;
};

int n, m, maxup[5000], nowc[5000];
op mas[5000];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        maxup[i] = 1e9;
    }
    for (int i = 0; i < m; ++i) {
        cin >> mas[i].t >> mas[i].l >> mas[i].r >> mas[i].dop;
        
        if (mas[i].t == 2) {
            for (int j = mas[i].l - 1; j < mas[i].r; ++j) {
                maxup[j] = min(maxup[j], mas[i].dop - nowc[j]);    
                //cout << mas[i].dop << " " << nowc[j] << endl;
            }
        } else {
            for (int j = mas[i].l - 1; j < mas[i].r; ++j) {
                nowc[j] += mas[i].dop;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        //cout << maxup[i] << " ";
        nowc[i] = maxup[i];
    }
    for (int i = 0; i < m; ++i) {
        //cin >> mas[i].t >> mas[i].l >> mas[i].r >> mas[i].dop;
        /*
        for (int j = 0; j < n; ++j) {
            cout << nowc[j] << " ";
        }
        cout << endl;
        */
        if (mas[i].t == 2) {
            bool truly = false;
            for (int j = mas[i].l - 1; j < mas[i].r; ++j) {
                if (nowc[j] == mas[i].dop) {
                    truly = true;
                    break;
                }
            }
            if (!truly) {
                cout << "NO";
                return 0;
            }
        } else {
            for (int j = mas[i].l - 1; j < mas[i].r; ++j) {
                nowc[j] += mas[i].dop;
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << maxup[i] << " ";
    }

    return 0;
}