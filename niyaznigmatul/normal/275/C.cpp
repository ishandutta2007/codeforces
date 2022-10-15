#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>

#define __int64 long long
using namespace std;

int main() {
    int n;
    __int64 k;
    vector <__int64> a;
    set<long long> numb;
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        __int64 t;
        cin >> t;
        numb.insert(t);
        a[i] = t;
    }
    int c = 0;
    set<long long> z;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        if (z.count(a[i])) continue;
        if (!numb.count(a[i] * k)) {
            ++c;
//            cerr << "f " << a[i] << "\n";
        } else if (numb.count(a[i] * k * k)) {
            ++c;
            z.insert(a[i] * k);
//            cerr << "g " << a[i] << "\n";
        }
    }
    cout << c;
    return 0;
}