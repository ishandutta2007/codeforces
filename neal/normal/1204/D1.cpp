#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;
    N = S.size();
    vector<int> ones;
    vector<bool> paired(N, false);

    for (int i = 0; i < N; i++)
        if (S[i] == '1') {
            ones.push_back(i);
        } else if (!ones.empty()) {
            paired[ones.back()] = paired[i] = true;
            ones.pop_back();
        }

    for (int i = 0; i < N; i++)
        if (S[i] == '1' && !paired[i])
            S[i] = '0';

    cout << S << '\n';
}