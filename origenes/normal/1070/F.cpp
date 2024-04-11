#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b, tot, ans;

vector<int> veca, vecb, vec;

bool cmp(const int& a, const int& b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        int val;
        cin >> s >> val;
        if (s == "11") {
            a++; b++; tot++;
            ans += val;
        } else if (s == "10") veca.push_back(val);
        else if (s == "01") vecb.push_back(val);
        else vec.push_back(val);
    }

    sort(veca.begin(), veca.end(), cmp);
    sort(vecb.begin(), vecb.end(), cmp);

    for (int i = 0; i < min(veca.size(), vecb.size()); i++) {
        a++; b++; tot += 2;
        ans += veca[i] + vecb[i];
    }

    if (veca.size() < vecb.size()) {
        for (int i = veca.size(); i < vecb.size(); i++) vec.push_back(vecb[i]);
    } else {
        for (int i = vecb.size(); i < veca.size(); i++) vec.push_back(veca[i]);
    }

    sort(vec.begin(), vec.end(), cmp);
    //cout << a << ' ' << b << ' ' << tot << endl;
    for (int u : vec) {
        if (a * 2 >= tot + 1) {
            tot++;
            ans += u;
        }
    }
    cout << ans << '\n';
    return 0;
}