#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int COUNT = 600;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> on_count(COUNT, 0);

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        int goal = b;
        int status = S[i] - '0';

        for (int t = 0; t < COUNT; t++) {
            if (t == goal) {
                status = 1 - status;
                goal += a;
            }

            on_count[t] += status;
        }
    }

    cout << *max_element(on_count.begin(), on_count.end()) << '\n';
}