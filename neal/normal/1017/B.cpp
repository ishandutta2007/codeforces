#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> A >> B;
    long long zeros = 0, ones = 0;

    for (int i = 0; i < N; i++)
        if (A[i] == '0')
            zeros++;
        else if (A[i] == '1')
            ones++;
        else
            assert(false);

    long long answer = zeros * ones;
    zeros = ones = 0;

    for (int i = 0; i < N; i++)
        if (B[i] == '1') {
            if (A[i] == '0')
                zeros++;
            else if (A[i] == '1')
                ones++;
        }

    answer -= zeros * ones;
    cout << answer << '\n';
    return 0;
}