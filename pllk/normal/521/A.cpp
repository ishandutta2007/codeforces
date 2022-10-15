#include <iostream>

using namespace std;

#define M 1000000007
#define ll long long

int n;
string s;
int c[128];
int pc, pm;

int main() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        c[s[i]]++;
    }
    for (int i = 0; i < 128; i++) {
        if (c[i] > pc) {
            pc = c[i];
            pm = 1;
        } else if (c[i] == pc) {
            pm++;
        }
    }
    ll t = 1;
    for (int i = 1; i <= n; i++) {
        t *= pm;
        t %= M;
    }
    cout << t << "\n";
}