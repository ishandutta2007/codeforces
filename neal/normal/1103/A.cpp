#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    bool has_vertical = false, has_horizontal = false;

    for (char c : S)
        if (c == '0') {
            if (has_vertical) {
                puts("3 1");
            } else {
                puts("1 1");
            }

            has_vertical = !has_vertical;
        } else {
            if (has_horizontal) {
                puts("4 1");
            } else {
                puts("4 3");
            }

            has_horizontal = !has_horizontal;
        }
}