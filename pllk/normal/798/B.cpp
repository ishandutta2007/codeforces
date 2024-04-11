#include <iostream>
#include <vector>

using namespace std;

#define A 999999999

int n;
vector<string> v;
int u = A;

int lol(string x) {
    int z = 0;
    for (int i = 0; i < v.size(); i++) {
        string y = v[i];
        int c = 0;
        while (x != y && c < 100) {
            y = y.substr(1)+y[0];
            c++;
        }
        if (x != y) return A;
        z += c;
    }
    return z;
}

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
        u = min(u,lol(v[i]));
    }
    if (u == A) u = -1;
    cout << u << "\n";
}