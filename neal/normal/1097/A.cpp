#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string table;
    cin >> table;
    bool possible = false;

    for (int i = 0; i < 5; i++) {
        string hand;
        cin >> hand;

        if (table[0] == hand[0] || table[1] == hand[1])
            possible = true;
    }

    puts(possible ? "YES" : "NO");
}