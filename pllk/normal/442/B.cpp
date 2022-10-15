#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
double t[111];

double laske(vector<double> v) {
    double u = 0;
    for (int i = 0; i < v.size(); i++) {
        double x = 1;
        for (int j = 0; j < v.size(); j++) {
            if (i == j) x *= v[j];
            else x *= (1-v[j]);
        }
        u += x;
    }
    return u;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    sort(t, t+n);
    double m = 0;
    for (int i = 0; i < n; i++) {
        vector<double> u;
        for (int j = i; j < n; j++) {
            u.push_back(t[j]);
        }
        double x = laske(u);
        m = max(m, x);
    }
    printf("%.9lf\n", m);
}