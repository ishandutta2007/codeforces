#include <iostream>
#include <algorithm>

using namespace std;

int a[4];

int main() {
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(&a[0], &a[4]);
    int t = 0;
    if (a[0] == a[1]) t++;
    if (a[1] == a[2]) t++;
    if (a[2] == a[3]) t++;
    cout << t << endl;
}