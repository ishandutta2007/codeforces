#include <iostream>

using namespace std;

int main() {
    int a{}, b{}, c{}, d{};
    cin >> a >> b >> c >> d;
    int cnt1{}, cnt2{};
    cnt1 = max(3 * a / 10, a - a / 250 * c);
    cnt2 = max(3 * b / 10, b - b / 250 * d);
    if (cnt1 == cnt2)
        cout << "Tie\n";
    if (cnt1 > cnt2)
        cout << "Misha\n";
    if (cnt1 < cnt2)
        cout << "Vasya\n";
    return 0;
}