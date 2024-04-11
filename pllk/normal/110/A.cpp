#include <iostream>

#define ll long long int

using namespace std;

int t(ll n) {
    if (n == 0) return 0;
    int a = n%10;
    if (a == 4 || a == 7) return t(n/10)+1;
    else return t(n/10);
}

bool l(int n) {
    if (n == 0) return false;
    if (n == 4) return true;
    if (n == 7) return true;
    int a = n%10;
    if (a == 4 || a == 7) return l(n/10);
    else return false;
}

int main() {
    ll n;
    cin >> n;
    if (l(t(n))) cout << "YES\n";
    else cout << "NO\n";
}