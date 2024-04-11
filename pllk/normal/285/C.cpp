#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int

using namespace std;

int n;
vector<int> p;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        p.push_back(a);
    }
    sort(p.begin(), p.end());
    ll t = 0;
    for (int i = 0; i < n; i++) {
        t += abs(i+1-p[i]);
    }
    cout << t << endl;
}