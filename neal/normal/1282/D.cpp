#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int query(string str) {
    cout << str << endl;
    int result;
    cin >> result;

    if (result == 0)
        exit(0);

    return result;
}

int main() {
    ios::sync_with_stdio(false);

    int x = query("a");
    int a_count = query(string(x, 'b'));
    int n = x + 1;
    string str(n, 'b');

    for (int i = 0; i < n; i++) {
        str[i] = 'a';

        if (query(str) < a_count)
            a_count--;
        else
            str[i] = 'b';
    }

    assert(false);
}