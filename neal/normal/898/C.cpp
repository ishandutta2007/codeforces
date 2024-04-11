#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

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

    map<string, set<string>> phone_numbers;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string frnd;
        cin >> frnd;
        int k;
        cin >> k;

        while (k-- > 0) {
            string number;
            cin >> number;
            phone_numbers[frnd].insert(number);
        }
    }

    cout << phone_numbers.size() << '\n';

    for (auto &pr : phone_numbers) {
        string frnd = pr.first;
        vector<string> numbers(pr.second.begin(), pr.second.end());
        int n = int(numbers.size());
        vector<string> filtered;

        for (int i = 0; i < n; i++) {
            bool bad = false;

            for (int j = 0; j < n; j++)
                if (numbers[i].size() < numbers[j].size() && numbers[j].substr(numbers[j].size() - numbers[i].size()) == numbers[i])
                    bad = true;

            if (!bad)
                filtered.push_back(numbers[i]);
        }

        cout << frnd << ' ' << filtered.size();

        for (string number : filtered)
            cout << ' ' << number;

        cout << '\n';
    }
}