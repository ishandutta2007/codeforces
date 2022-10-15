#include <iostream>

#define ll long long int
#define S 60

using namespace std;

int n, m;
int t[1000][1000];
int b;
ll q[1000][50];

bool tutki(int r) {
    //cout << "juuh\n";
    for (int i = 0; i < n; i++) {
        ll w = 0;
        int v = 0;
        for (int j = 0; j < m; j++) {
            w *= 2;
            if (t[i][j] >= r) w++;
            if ((j+1)%S == 0) {
                q[i][v] = w;
                w = 0;
                v++;
            }
        }
        q[i][v] = w;
        //cout << i << " " << v << " " << w << endl;
    }
    //cout << "elikks\n";
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            ll s = 0;
            int c = 0;
            for (int k = 0; k < b; k++) {
                ll h = q[i][k] & q[j][k];
                if (h > 0) h -= (h & -h); else continue;
                if (h > 0) c += 2; else c++;
            }
            //cout << i << " " << j << " " << c << endl;
            if (c >= 2) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int p = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> t[i][j];
            if (t[i][j] > p) p = t[i][j];
        }
    }
    if (m%S == 0) b = m/S; else b = m/S+1;
    if (p < 2) p = 2;
    int x = 0;
    for (int a = p/2; a >= 1; a /= 2) {
        while (x+a <= p && tutki(x+a)) x += a;
    }
    cout << x << endl;
}