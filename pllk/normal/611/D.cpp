#include <iostream>

using namespace std;

int n;
string s;

#define M 1000000007

int d[5050][5050];
int q[5050][5050];

int laske(int a, int b) {
    if (b > n) return 0;
    if (d[a][b]) return d[a][b];
    int u = 0;
    if (s[a] == s[b]) u = 1+laske(a+1,b+1);
    else u = 0;
    d[a][b] = u;
    return u;
}

bool ok(int a, int b, int x) {
    if (s[a] < s[b]) return 1;
    if (s[a] > s[b]) return 0;
    int v = laske(a,b);
    for (int i = v; i < x; i++) {
        if (s[a+i] < s[b+i]) return 1;
        if (s[a+i] > s[b+i]) return 0;
    }
    return 0;
}


int main() {
    cin >> n;
    cin >> s;
    s = "*"+s;
    for (int k = 1; k <= n; k++) {
        for (int x = 1; x <= k; x++) {
            int u = 0;
            if (x == k) {u = 1; goto ohi;}
            if (s[k-x+1] == '0') goto ohi;
            u = q[k-x][min(x-1,k-x)];
            /*for (int z = 1; z < x && x+z <= k; z++) {
                u += d[k-x][z];
                u %= M;
            }*/
            if (2*x <= k && ok(k-2*x+1,k-x+1,x)) u += q[k-x][x]-q[k-x][x-1];
            u %= M;
            ohi:
            //d[k][x] = u;
            q[k][x] = u;
            q[k][x] += q[k][x-1];
            q[k][x] %= M;
        }
    }
    /*int c = 0;
    for (int i = 1; i <= n; i++) {
        c += d[n][i];
        c %= M;
    }*/
    cout << q[n][n] << "\n";
}