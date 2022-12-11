#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 10;

using pii = pair<int, int>;

vector<pii> data[N];

long long x[N];
int n;

int main() {

    for (int i = 1; i < N; ++i) {
        if (i <= N/i)
        for (int j = i + 2; j * i < N; j += 2) {
            data[i*j].push_back({(j-i)/2, (j+i)/2});
        }

        sort(data[i].begin(), data[i].end());
    }

    cin >> n;
    for (int i = 1; i < n; i += 2) {
        cin >> x[i];
    }

    long long c = 0;
    for (int i = 0; i < n; i += 2) {

        auto &d = data[x[i+1]];
        auto it = lower_bound(d.begin(), d.end(), pii(c, c));

        if (it == d.end()) {
            cout << "No" << endl;
            return 0;
        }

        long long b = it->first, a = it->second;
        x[i] = b * b - c * c;
        assert(a * a - b * b == x[i+1]);

        c = a;
    }

    cout << "Yes" << endl;
    for (int i = 0; i < n; ++i) {
        cout << x[i] << " ";
    }
    cout << endl;

    return 0;
}