#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int a, b, k1, k2, k3;
    k1 = k2 = k3 = 0;
    cin >> a >> b;
    for (int i = 1; i <= 6; i++) {
        if (abs(i - a) < abs(i - b)) k1++;
        if (abs(i - a) == abs(i - b)) k2++;
        if (abs(i - a) > abs(i - b)) k3++;
    }
    cout << k1 << " " << k2 << " " << k3 << endl;
    return 0;
}