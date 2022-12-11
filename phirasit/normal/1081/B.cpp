#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    map<int, int> cnt;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    map<int, int> group;

    int c = 1;
    for (auto it : cnt) {
        group[it.first] = c;

        int val = n - it.first;
        if (it.second % val) {
            cout << "Impossible" << endl;
            return 0;
        }

        c += it.second / val;
    }

    map<int, int> rem;

    cout << "Possible" << endl;
    for (int i = 0; i < n; ++i) {
        cout << (group[a[i]] + rem[a[i]] / (n - a[i])) << " ";
        rem[a[i]]++;
    }
    cout << endl;

    return 0;
}