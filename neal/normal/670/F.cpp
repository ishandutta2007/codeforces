#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    string str, sub;
    cin >> str >> sub;
    sort(str.begin(), str.end());
    int n = int(str.size());
    int correct = -1;

    if (str == "01") {
        cout << "0" << '\n';
        return 0;
    }

    for (int len = 1; len <= n; len++)
        if (len + int(to_string(len).size()) == n) {
            correct = len;
            break;
        }

    assert(correct >= 0);
    cerr << correct << endl;
    vector<int> freq(10, 0);

    for (auto &ch : str)
        freq[ch - '0']++;

    for (auto &ch : to_string(correct))
        freq[ch - '0']--;

    cerr << freq << endl;

    for (auto &ch : sub)
        freq[ch - '0']--;

    int start = 1;

    while (start < 10 && freq[start] == 0)
        start++;

    if (start == 10)
        start = 0;

    bool up = true;

    for (int i = 0; i < int(sub.size()) - 1; i++)
        if (sub[i + 1] > sub[i]) {
            up = true;
            break;
        } else if (sub[i + 1] < sub[i]) {
            up = false;
            break;
        }

    int x = sub[0] - '0';

    if (up)
        x++;

    string start_sub = sub;

    for (int i = 0; i < 10; i++)
        for (int c = 0; c < freq[i]; c++)
            start_sub += char(i + '0');

    string not_sub;
    not_sub += char(start + '0');
    freq[start]--;

    for (int i = 0; i < x; i++)
        for (int c = 0; c < freq[i]; c++)
            not_sub += char(i + '0');

    not_sub += sub;

    for (int i = x; i < 10; i++)
        for (int c = 0; c < freq[i]; c++)
            not_sub += char(i + '0');

    if (start_sub[0] == '0')
        cout << not_sub << '\n';
    else if (not_sub[0] == '0')
        cout << start_sub << '\n';
    else
        cout << min(start_sub, not_sub) << '\n';
}