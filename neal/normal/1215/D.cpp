#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string ANSWERS[2] = {"Monocarp", "Bicarp"};

int N, H;
string ticket;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> ticket;
    H = N / 2;

    int sum[2] = {0, 0};
    int missing[2] = {0, 0};

    for (int i = 0; i < N; i++)
        if (ticket[i] == '?')
            missing[i / H]++;
        else
            sum[i / H] += ticket[i] - '0';

    if (sum[0] + 4.5 * missing[0] == sum[1] + 4.5 * missing[1])
        cout << ANSWERS[1] << '\n';
    else
        cout << ANSWERS[0] << '\n';
}