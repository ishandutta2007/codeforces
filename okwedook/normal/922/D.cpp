#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct p {
    ll h, s;
    string str;
    p () {

    }
};

bool operator<(const p &a, const p &b) {
    return (a.h * b.s < b.h * a.s);
}

int main() {
    ll t;
    cin >> t;
    vector<p> arr(t);
    for (int i = 0; i < t; ++i) {
        cin >> arr[i].str;
        ll cs = 0, ch = 0;
        for (auto i : arr[i].str) {
            cs += (i == 's');
            ch += (i == 'h');
        }
        arr[i].s = cs;
        arr[i].h = ch;
    }
    sort(arr.begin(), arr.end());
    string ans = "";
    for (auto &i : arr) ans += i.str;
    ll count = 0, answ = 0;
    for (auto i : ans) {
        if (i == 's') ++count;
        else answ += count;
    }
    cout << answ;
    //system("pause");
    return 0;
}