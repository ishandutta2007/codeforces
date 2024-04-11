#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string PERSON[2] = {"sjfnb", "cslnb"};

int N;
vector<long long> A;

void winner(int who) {
    assert(who == 0 || who == 1);
    cout << PERSON[who] << '\n';
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    sort(A.begin(), A.end());
    int equal_count = 0;
    int equal_pos = -1;

    for (int i = 0; i + 1 < N; i++)
        if (A[i] == A[i + 1]) {
            equal_count++;
            equal_pos = i;
        }

    if (equal_count > 1)
        winner(1);

    bool flip = false;

    if (equal_count > 0) {
        if (equal_pos > 0 && A[equal_pos - 1] + 1 == A[equal_pos])
            winner(1);

        if (A[equal_pos] == 0)
            winner(1);

        A[equal_pos]--;
        flip = true;
    }

    for (int i = 0; i + 1 < N; i++)
        assert(A[i] < A[i + 1]);

    long long sum = 0;

    for (int i = 0; i < N; i++)
        sum += A[i] - i;

    winner((sum % 2 == 0) ^ flip);
}