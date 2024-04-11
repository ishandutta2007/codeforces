#include <iostream>
#include <unordered_map>

using namespace std;

#define ll long long

int n;
int x[2222], y[2222];
ll c;

int syt(int a, int b) {
    if (b == 0) return a;
    return syt(b, a%b);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for (int i = 0; i < n; i++) {
        unordered_map<int, unordered_map<int,int>> z;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int dx = x[i]-x[j];
            int dy = y[i]-y[j];
            if (dy == 0) {
                z[-2][-2]++;
            } else if (dx == 0) {
                z[2][2]++;
            } else {
                int g = syt(dx,dy);
                dx /= g;
                dy /= g;
                if (dx < 0) {dx *= -1; dy *= -1;}
                z[dx][dy]++;
            }
        }
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int dx = x[i]-x[j];
            int dy = y[i]-y[j];
            int u = n-1;
            if (dy == 0) {
                u -= z[-2][-2];
            } else if (dx == 0) {
                u -= z[2][2];
            } else {
                int g = syt(dx,dy);
                dx /= g;
                dy /= g;
                if (dx < 0) {dx *= -1; dy *= -1;}
                u -= z[dx][dy];
            }
            c += u;
        }
    }
    cout << c/6 << "\n";
}