#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> minimum(N), maximum(N);
    long long min_sum = 0;

    for (int i = 0; i < N; i++) {
        double x;
        cin >> x;
        minimum[i] = floor(x);
        maximum[i] = ceil(x);
        min_sum += minimum[i];
    }

    for (int i = 0; i < N; i++)
        if (minimum[i] == maximum[i] || min_sum == 0) {
            cout << minimum[i] << '\n';
        } else {
            cout << maximum[i] << '\n';
            min_sum++;
        }
}