#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, string>> filter_sequence(vector<pair<int, string>> sequence, int K) {
    vector<pair<int, string>> filtered;

    for (auto &pr : sequence) {
        if (pr.first == 0)
            continue;

        if (pr.first * (int) pr.second.size() <= K) {
            filtered.push_back(pr);
            K -= pr.first * pr.second.size();
        } else {
            if (K / pr.second.size() != 0)
                filtered.emplace_back(K / pr.second.size(), pr.second);

            if (K % pr.second.size() != 0)
                filtered.emplace_back(1, pr.second.substr(0, K % pr.second.size()));

            break;
        }
    }

    return filtered;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    if (K > 4 * N * M - 2 * N - 2 * M) {
        cout << "NO" << '\n';
        return 0;
    }

    vector<pair<int, string>> sequence;

    for (int i = 0; i < N - 1; i++) {
        sequence.emplace_back(M - 1, "RDU");
        sequence.emplace_back(M - 1, "L");
        sequence.emplace_back(1, "D");
    }

    sequence.emplace_back(M - 1, "R");
    sequence.emplace_back(M - 1, "L");
    sequence.emplace_back(N - 1, "U");

    vector<pair<int, string>> filtered = filter_sequence(sequence, K);
    cout << "YES" << '\n';
    cout << filtered.size() << '\n';

    for (auto &pr : filtered)
        cout << pr.first << ' ' << pr.second << '\n';
}