#include <iostream>

#define ll long long int
#define M 1000000007

using namespace std;

int n;
string s, w;

int main() {
    cin >> n >> s >> w;
    ll t1 = 1;
    for (int i = 0; i < n; i++) {
        int m = 0;
        for (int a = 0; a <= 9; a++) {
            for (int b = a; b <= 9; b++) {
                if (s[i] != '?' && s[i] != '0'+a) continue;
                if (w[i] != '?' && w[i] != '0'+b) continue;
                m++;
            }
        }
        t1 *= m;
        t1 %= M;
    }
    ll t2 = 1;
    for (int i = 0; i < n; i++) {
        int m = 0;
        for (int a = 0; a <= 9; a++) {
            for (int b = a; b <= 9; b++) {
                if (s[i] != '?' && s[i] != '0'+b) continue;
                if (w[i] != '?' && w[i] != '0'+a) continue;
                m++;
            }
        }
        t2 *= m;
        t2 %= M;
    }
    ll t3 = 1;
    for (int i = 0; i < n; i++) {
        int m = 0;
        for (int a = 0; a <= 9; a++) {
            if (s[i] != '?' && s[i] != '0'+a) continue;
            if (w[i] != '?' && w[i] != '0'+a) continue;
            m++;
        }
        t3 *= m;
        t3 %= M;
    }
    ll t4 = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') t4 *= 10;
        if (w[i] == '?') t4 *= 10;
        t4 %= M;
    }
    t4 -= t1;
    t4 -= t2;
    t4 += t3;
    while (t4 < 0) t4 += M;
    cout << t4 << endl;
}