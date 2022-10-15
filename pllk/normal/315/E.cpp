#include <iostream>

#define ll long long int
#define N (1<<20)
#define V 1000000007

using namespace std;

ll p[2*N];

int muuta(int k, ll a) {
    k += N;
    p[k] = a;
    k /= 2;
    while (k >= 1) {
        p[k] = p[2*k]+p[2*k+1];
        p[k] = p[k]%V;
        k /= 2;
    }
}

ll haku(int a, int b) {
    a += N;
    b += N;
    ll t = 0;
    while (a <= b) {
        if (a%2 == 1) {
            t += p[a];
            a++;
        }
        if (b%2 == 0) {
            t += p[b];
            b--;
        }
        a /= 2;
        b /= 2;
        t %= V;
    }
    return t;
}

int n;
ll aa[200000];

ll t;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> aa[i];
    }
    for (int i = n-1; i >= 0; i--) {
        ll u = haku(aa[i],1000000)*aa[i];
        u += aa[i];
        u = u%V;
        muuta(aa[i], u);
    }
    for (int i = 1; i <= 1000000; i++) {
        t += haku(i, i);
        t %= V;
    }
    cout << t << endl;
}