#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int ask(string s) {
    cout << s << endl;
    int x;
    cin >> x;
    if (x == 0) {
        exit(0);
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);

    int na = 300 - ask(string(300, 'a'));
    int nb = 300 - ask(string(300, 'b'));

    int n = na + nb;

    string res(n, '.');
    for (int i = 0; i < n - 1; i++) {
        string s(n, 'a');
        s[i] = 'b';
        int x = ask(s);
        if (x < nb) {
            res[i] = 'b';
        } else {
            res[i] = 'a';
        }
    }

    int bc = 0;
    for (int i = 0; i < n - 1; i++) {
        if (res[i] == 'b') bc++;
    }

    if (nb != bc) {
        res[n - 1] = 'b';
    } else {
        res[n - 1] = 'a';
    }

    ask(res);
    assert(false);

    return 0;
}