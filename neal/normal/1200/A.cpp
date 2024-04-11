#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string rooms(10, '0');
    int n;
    string events;
    cin >> n >> events;

    for (char c : events)
        if (c == 'L') {
            int index = 0;

            while (rooms[index] == '1')
                index++;

            rooms[index] = '1';
        } else if (c == 'R') {
            int index = 9;

            while (rooms[index] == '1')
                index--;

            rooms[index] = '1';
        } else {
            rooms[c - '0'] = '0';
        }

    cout << rooms << '\n';
}