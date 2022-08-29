#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long counts[2] = {0, 0};
    long long prefixes[2] = {0, 0};
    prefixes[0]++;

    int sum = 0;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        a = a < 0 ? 1 : 0;
        sum = (sum + a) % 2;
        counts[0] += prefixes[sum];
        counts[1] += prefixes[1 - sum];
        prefixes[sum]++;
    }

    cout << counts[1] << ' ' << counts[0] << '\n';
}