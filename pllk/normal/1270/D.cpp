#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;

int main() {
    cin >> n >> k;
    vector<int> v;
    for (int i = 1; i <= k+1; i++) {
        cout << "? ";
        for (int j = 1; j <= k+1; j++) {
            if (i != j) cout << j << " ";
        }
        cout << endl;
        int p, a;
        cin >> p >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for (int i = 0; ; i++) {
        if (v[i] != v[i+1]) {
            cout << "! " << k-i << "\n";
            return 0;
        }
    }
}