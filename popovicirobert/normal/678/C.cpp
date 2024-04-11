#include <bits/stdc++.h>


using namespace std;

inline long long gcd(long long a, long long b) {
    long long r;
    while(b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    long long n, a, b, p, q;
    //ios::sync_with_stdio(false);
    cin >> n >> a >> b >> p >> q;
    long long x = a * b / gcd(a, b);
    cout << p * (n / a) + q * (n / b) - (n / x) * min(p, q);
    //cin.close();
    //cout.close();
    return 0;
}