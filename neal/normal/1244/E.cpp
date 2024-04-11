#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N;
long long K;
map<long long, long long> freq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        freq[a]++;
    }

    while (freq.size() > 1 && K > 0) {
        auto first = freq.begin();
        auto last = --freq.end();

        if (first->second < last->second) {
            auto second = ++freq.begin();

            if (first->second * (second->first - first->first) <= K) {
                K -= first->second * (second->first - first->first);
                freq[second->first] += first->second;
                freq.erase(first);
            } else {
                if (K >= first->second) {
                    freq[first->first + K / first->second] = first->second;
                    freq.erase(first);
                }

                K = 0;
            }
        } else {
            auto second_last = --(--freq.end());

            if (last->second * (last->first - second_last->first) <= K) {
                K -= last->second * (last->first - second_last->first);
                freq[second_last->first] += last->second;
                freq.erase(last);
            } else {
                if (K >= last->second) {
                    freq[last->first - K / last->second] += last->second;
                    freq.erase(last);
                }

                K = 0;
            }
        }
    }

    cout << (--freq.end())->first - freq.begin()->first << '\n';
}