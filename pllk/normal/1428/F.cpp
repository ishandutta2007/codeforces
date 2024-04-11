#include <iostream>

using namespace std;

typedef long long ll;

int n;
string s;
ll d[1222333];

ll r;

#define N (1<<19)
int p[2*N];

void setVal(int k, int x) {
    k += N;
    p[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        p[k] = max(p[2*k],p[2*k+1]);
    }
}

int getMax(int a, int b) {
    a += N; b += N;
    int m = 0;
    while (a <= b) {
        if (a%2 == 1) m = max(m,p[a++]);
        if (b%2 == 0) m = max(m,p[b--]);
        a /= 2; b /= 2;
    }
    return m;
}

int main() {
    cin >> n;
    cin >> s;
    s = "#"+s;
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') c++;
        else c = 0;
        setVal(c,i);
        ll u = 0;
        u += ((ll)c)*(c+1)/2;
        int v = getMax(c+1,n);
        if (v == 0) {
            u += ((ll)c)*(i-c);
        } else {
            u += ((ll)c)*(i-c-(v-c+1))-((ll)c)*(c-1)/2;
            u += d[v];
        }
        d[i] = u;
        r += u;
        //cout << i << " " << d[i] << "\n";
    }
    cout << r << "\n";
}