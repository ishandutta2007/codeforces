#include <iostream>

using namespace std;

#define N (1<<18)

typedef long long ll;

ll p[2*N];

void setVal(int k, int x) {
    k += N;
    p[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        p[k] = p[2*k]+p[2*k+1];
    }
}

ll getSum(int a, int b) {
    a += N; b += N;
    ll s = 0;
    while (a <= b) {
        if (a%2 == 1) s += p[a++];
        if (b%2 == 0) s += p[b--];
        a /= 2; b /= 2;
    }
    return s;
}

int n;
ll s[202020];
int r[202020];

int query(ll x) {
    int k = 0;
    for (int b = n; b >= 1; b /= 2) {
        while (k+b <= n && getSum(1,k+b) <= x) k += b;
    }
    return k+1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) setVal(i,i);
    for (int i = n; i >= 1; i--) {
        r[i] = query(s[i]);
        setVal(r[i],0);
    }
    for (int i = 1; i <= n; i++) cout << r[i] << " ";
    cout << "\n";
}