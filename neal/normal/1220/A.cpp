#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;

    int zero = count(S.begin(), S.end(), 'z');
    int one = count(S.begin(), S.end(), 'n');

    for (int i = 0; i < one + zero; i++)
        cout << (i < one ? 1 : 0) << (i < one + zero - 1 ? ' ' : '\n');
}