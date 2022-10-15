#include <iostream>

using namespace std;

typedef long long ll;

#define M 998244353

int pos1(int x, int k) {
    int u = 0;
    for (int i = 0; i <= k-1; i++) {
        if (x) {u++; x--;}
        u++;
    }
    return u;
}

int pos2(int x, int k) {
    int u = 0;
    x--;
    for (int i = 0; i <= k-1; i++) {
        u++;
        if (x) {u++; x--;}
    }
    u++;
    return u;
}

int n;
int c[11];
int a[101010];
ll b[50];

int main() {
    b[0] = 1;
    for (int i = 1; i < 30; i++) b[i] = b[i-1]*10%M;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[to_string(a[i]).size()]++;
    }
    ll cc = 0;
    for (int i = 1; i <= n; i++) {
        string s = to_string(a[i]);
        int k = s.size();
        for (int j = 0; j < k; j++) {
            for (int h = 1; h <= 10; h++) {
                int p1 = pos1(h,j);
                int p2 = pos2(h,j);
                cc += c[h]*(b[p1]+b[p2])*(s[k-j-1]-'0');
                cc %= M;
            }
        }
    }
    cout << cc << "\n";
}