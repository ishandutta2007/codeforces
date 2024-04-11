#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string puppies;
    int n;
    cin >> n;
    cin >> puppies;
    map<char, int> colors;

    for (char c : puppies)
        colors[c]++;

    bool yes = colors.size() == 1;
    bool has_two = false;

    for (pair<char, int> p : colors)
        if (p.second >= 2)
            has_two = true;

    yes = yes || has_two;
    cout << (yes ? "Yes" : "No") << '\n';
    return 0;
}