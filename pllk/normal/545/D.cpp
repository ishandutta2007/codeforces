#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int n;
vector<int> v;
ll s;
int c;

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < v.size(); i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        if (s > v[i]) continue;
        s += v[i];
        c++;
    }
    cout << c << "\n";
}