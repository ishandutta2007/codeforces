#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

ull recurse(ull l, ull r) {
    if (l == r)
        return 0;
    ull temp = r;
    int c = 0;

    while (temp) {
        temp >>= 1;
        c += 1;
    }
    c -= 1;
    if (l >= ((ull)1 << c)) {
        l -= ((ull)1 << c);
        r -= ((ull)1 << c);
        return recurse(l, r);
    }
    return ((ull)1 << c) ^ (((ull)1 << c) - 1);
}

int main() {
    ios::sync_with_stdio(false);

    ull l, r;
    cin >> l >> r;

    ull temp;
    int c = 0;

//    ull ans = -1;
//    while ((1 << c) <= l) {
//        temp = r;
//        c = 0;
//
//        while (temp) {
//            temp >>= 1;
//            c += 1;
//        }
//        c -= 1;
//        if (l >= (1 << c)) {
//            l -= (1 << c);
//            r -= (1 << c);
//        }
//        ans = (1 << c) ^ ((1 << c) - 1);
//    }

    cout << recurse(l, r);
    return 0;
}