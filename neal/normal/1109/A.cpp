#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N;
vector<int> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    vector<int> prefix(N + 1, 0);

    for (int i = 0; i < N; i++)
        prefix[i + 1] = prefix[i] ^ A[i];

    map<int, int> freq[2];
    long long total = 0;

    for (int i = 0; i <= N; i++) {
        total += freq[i % 2][prefix[i]];
        freq[i % 2][prefix[i]]++;
    }

    cout << total << '\n';
}