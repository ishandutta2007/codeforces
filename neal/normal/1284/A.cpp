#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<string> S(N), T(M);

    for (string &s : S)
        cin >> s;

    for (string &t : T)
        cin >> t;

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int year;
        cin >> year;
        year--;
        year %= N * M;
        int n = year % N;
        int m = year % M;
        cout << S[n] + T[m] << '\n';
    }
}