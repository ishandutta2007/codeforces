#include <iostream>
#include <vector>
#include <algorithm>

#define A 999999999

using namespace std;

typedef long long ll;

vector<ll> x;

int hh;

void haku(ll a, ll b, ll w, ll h, ll f, int g, int k) {
    if (k >= hh) return;
    if (a <= w && b <= h) {
        hh = min(hh,k);
        return;
    }
    if (k == x.size()) return;
    if (w < a && (f != x[k] || g != 2)) {
        haku(a,b,w*x[k],h,x[k],1,k+1);
    }
    if (h < b) {
        haku(a,b,w,h*x[k],x[k],2,k+1);
    }
}

int lol(int a, int b, int w, int h) {
    hh = A;
    haku(a,b,w,h,0,0,0);
    return hh;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;
    x.resize(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x.rbegin(),x.rend());
    while (x.size() > 34) x.pop_back();
    int r = A;
    r = min(r,lol(a,b,h,w));
    r = min(r,lol(a,b,w,h));
    if (r == A) r = -1;
    cout << r << "\n";
}