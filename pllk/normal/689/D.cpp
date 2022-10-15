#include <iostream>

using namespace std;

typedef long long ll;

#define N (1<<18)

int n;
int p1[2*N];
int p2[2*N];

void muuta1(int k, int x) {
    k += N;
    p1[k] = x;
    for (k /= 2; k >= 1; k /= 2) p1[k] = min(p1[2*k],p1[2*k+1]);
}

void muuta2(int k, int x) {
    k += N;
    p2[k] = x;
    for (k /= 2; k >= 1; k /= 2) p2[k] = max(p2[2*k],p2[2*k+1]);
}

int pienin(int a, int b) {
    a += N; b += N;
    int p = p1[a];
    while (a <= b) {
        if (a%2 == 1) p = min(p,p1[a++]);
        if (b%2 == 0) p = min(p,p1[b--]);
        a /= 2; b /= 2;
    }
    return p;
}

int suurin(int a, int b) {
    a += N; b += N;
    int s = p2[a];
    while (a <= b) {
        if (a%2 == 1) s = max(s,p2[a++]);
        if (b%2 == 0) s = max(s,p2[b--]);
        a /= 2; b /= 2;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        muuta2(i,x);
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        muuta1(i,x);
    }
    ll z = 0;
    for (int i = 1; i <= n; i++) {
        int u1 = i-1, u2 = i-1;
        for (int b = n; b >= 1; b /= 2) {
            while (u1+b <= n && pienin(i,u1+b) > suurin(i,u1+b)) u1 += b;
            while (u2+b <= n && pienin(i,u2+b) >= suurin(i,u2+b)) u2 += b;
        }
        z += u2-u1;
    }
    cout << z << "\n";
}