#include <iostream>

using namespace std;

typedef long long ll;

int n, m;
int a[202020];

#define N (1<<19)
#define Z (1<<18)
int p[2*N];

void add(int k, int x) {
    k += N;
    p[k] += x;
    for (k /= 2; k >= 1; k /= 2) p[k] = p[2*k]+p[2*k+1];
}

int sum(int a, int b) {
    a += N; b += N;
    int s = 0;
    while (a <= b) {
        if (a%2 == 1) s += p[a++];
        if (b%2 == 0) s += p[b--];
        a /= 2; b /= 2;
    }
    return s;
}

ll calc(ll x) {
    for (int i = 0; i < 2*N; i++) p[i] = 0;
    add(Z+0,1);
    int c = 0;
    ll u = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= x) c++;
        else c--;
        u += sum(0,Z+c);
        add(Z+c,1);
    }
    return u;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << calc(m)-calc(m-1) << "\n";
}