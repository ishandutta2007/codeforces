#include <algorithm>
#include <array>
#include <cassert>
#include <deque>
#include <iostream>
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


string reversed(string str) {
    reverse(str.begin(), str.end());
    return str;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    string S;
    cin >> S;
    int N = int(S.size());
    vector<pair<int, string>> answers(N);
    string rev_answer;
    deque<pair<char, int>> runs = {{0, 0}};
    bool previous_still_in = false;

    for (int i = N - 1; i >= 0; i--) {
        if (!runs.empty() && runs.front().first == S[i])
            runs.front().second++;
        else
            runs.emplace_front(S[i], 1);

        rev_answer += S[i];

        if (runs.front().second >= 2 && previous_still_in && runs[1].first < S[i]) {
            rev_answer.pop_back();
            rev_answer.pop_back();
            runs.front().second -= 2;

            if (runs.front().second == 0)
                runs.pop_front();

            previous_still_in = false;
        } else {
            previous_still_in = true;
        }

        int len = int(rev_answer.size());
        answers[i].first = len;

        if (len <= 10)
            answers[i].second = reversed(rev_answer);
        else
            answers[i].second = reversed(rev_answer.substr(len - 5)) + "..." + reversed(rev_answer.substr(0, 2));
    }

    for (int i = 0; i < N; i++)
        cout << answers[i].first << ' ' << answers[i].second << '\n';
}