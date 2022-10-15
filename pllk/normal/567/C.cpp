#include <iostream>
#include <unordered_map>

using namespace std;

#define ll long long

int n, k;
unordered_map<int,ll> c[3];
ll s;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x%k == 0) {
            c[2][x] += c[1][x/k];
            s += c[1][x/k];
            c[1][x] += c[0][x/k];
        }
        c[0][x]++;
    }
    cout << s << "\n";
}