#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {

    int n;
    double r;

    cout << setprecision(10) << fixed;

    cin >> n >> r;
    double x[n], y[n];
    for (int i = 0; i < n; ++i) {
        cin >> x[i];

        y[i] = r;
        for (int j = 0; j < i; ++j) {
            double dx = fabs(x[i]-x[j]);
            if (dx <= 2*r) {
                double dy = sqrt(pow(2*r, 2) - pow(dx, 2));
                y[i] = max(y[i], y[j] + dy);
            }
        }
    
        cout << y[i] << " ";
    }
    cout << endl;

    return 0;
}