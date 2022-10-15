#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int rr[222];
int gg[222];
int bb[222];

int dv[222][222][222];
ll dd[222][222][222];

ll calc(int r, int g, int b) {
    if (dv[r][g][b]) return dd[r][g][b];
    ll u = 0;
    if (r >= 1 && g >= 1) {
        u = max(u,calc(r-1,g-1,b)+rr[r]*gg[g]);
    }
    if (r >= 1 && b >= 1) {
        u = max(u,calc(r-1,g,b-1)+rr[r]*bb[b]);
    }
    if (g >= 1 && b >= 1) {
        u = max(u,calc(r,g-1,b-1)+gg[g]*bb[b]);
    }
    dv[r][g][b] = 1;
    dd[r][g][b] = u;
    return u;
}

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    for (int i = 1; i <= r; i++) cin >> rr[i];
    for (int i = 1; i <= g; i++) cin >> gg[i];
    for (int i = 1; i <= b; i++) cin >> bb[i];
    sort(rr+1,rr+r+1);
    sort(gg+1,gg+g+1);
    sort(bb+1,bb+b+1);
    cout << calc(r,g,b) << "\n";
}