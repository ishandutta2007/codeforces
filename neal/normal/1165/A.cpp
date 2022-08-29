#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X, Y;
    string number;
    cin >> N >> X >> Y >> number;
    int change = 0;
    reverse(number.begin(), number.end());

    for (int i = 0; i < X; i++)
        if ((number[i] == '1') ^ (i == Y))
            change++;

    cout << change << '\n';
}