#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> t;
int T;

int main() {
    cin >> n;
    t.resize(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    sort(t.begin(), t.end());
    cin >> T;
    int m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (j-i+1 > m && t[j]-t[i] <= T) m = j-i+1;
        }
    }
    cout << m << endl;
}