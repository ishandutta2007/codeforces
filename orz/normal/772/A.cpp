#include <iostream>
#include <vector>

#define long long long
//#define double long double

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    long p;
    cin >> n >> p;
    vector<pair<long, double>> devices;
    long sum = 0, get = 0;
    for (int i = 0; i < n; i++) {
        long a, b;
        cin >> a >> b;
        get += a;
        sum += b;
        devices.push_back(make_pair(a, b));
    }

    if (get <= p) {
        cout << -1 << endl;
        return 0;
    }

    double l = 0, r = (double) sum / (get - p);
    while (r - l > 1e-6) {
        double m = (l + r) / 2;
        double time = 0;
        for (int i = 0; i < n; i++) {
            if (devices[i].second < devices[i].first * m) {
            	time += (m * devices[i].first - devices[i].second) / p;
            }
        }

        if (time > m) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << l << endl;
    return 0;
}