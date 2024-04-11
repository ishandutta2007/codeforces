#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>

// @author: pashka

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int n, m;

    cin >> n >> m;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> res;

    int j = 0;
    int s = 0;
    for (int i = 1; i <= m; i++) {
        while (j < n && a[j] < i) j++;
        if (j == n || a[j] > i) {
            if (s + i <= m) {
                res.push_back(i);
                s += i;
            }
        }
        if (s + i > m) break;
    }

    cout << res.size() << endl;
    for (auto item : res) {
        cout << item << " ";
    }
    cout << endl;


    return 0;
}