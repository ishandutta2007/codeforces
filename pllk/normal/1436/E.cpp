#include <iostream>

using namespace std;

// [1,4,3,1,2]
//  2 1 1 2 1
//  2 1 2 3
//  2 2 4
//  2 5

int n;
int a[101010];

#define N (1<<17)
int p[2*N];

void setVal(int k, int x) {
    k += N;
    p[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        p[k] = min(p[2*k],p[2*k+1]);
    }
}

int getMin(int a, int b) {
    a += N; b += N;
    int r = p[a];
    while (a <= b) {
        if (a%2 == 1) r = min(r,p[a++]);
        if (b%2 == 0) r = min(r,p[b--]);
        a /= 2; b /= 2;
    }
    return r;
}

int f[101010];
int m[101010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1) m[1] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] != 1) {
            if (getMin(1,a[i]-1) >= max(1,f[a[i]])) m[a[i]] = 1;
        }
        f[a[i]] = i;
        setVal(a[i],i);
    }
    for (int i = 2; i <= n+1; i++) {
        if (getMin(1,i-1) >= max(1,f[i])) m[i] = 1;
    }
    for (int i = 1; i <= n+2; i++) {
        if (!m[i]) {
            cout << i << "\n";
            break;
        }
    }
}