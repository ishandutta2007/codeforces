#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const double PI = acos(-1);

int main() {
    double N, R;
    cin >> N >> R;
    double cosine = cos(2 * PI / N);
    double x = sqrt((1 - cosine) / 2);
    double radius = R * x / (1 - x);
    cout << fixed << setprecision(12) << radius << '\n';
}