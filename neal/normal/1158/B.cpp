#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int length = (N - K) / 2 + 1;
    string build = "";

    for (int i = 0; i < length; i++)
        build += i < length - 1 ? '0' : '1';

    string S = "";

    for (int i = 0; i < N; i++)
        S += build[i % length];

    cout << S << '\n';
}