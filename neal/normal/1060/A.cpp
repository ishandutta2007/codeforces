#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    string digits;
    cin >> n >> digits;
    int eights = 0;

    for (char d : digits)
        if (d == '8')
            eights++;

    cout << min(n / 11, eights) << '\n';
}