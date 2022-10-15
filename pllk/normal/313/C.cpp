#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int

using namespace std;

int n;
vector<int> v;
ll t;

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    for (int i = 1; i <= n; i *= 4) {
        for (int j = 0; j < i; j++) {
            t += v[j];
        }
    }
    cout << t << endl;
}