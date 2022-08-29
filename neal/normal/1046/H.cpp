#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int LETTERS = 26;

uint16_t freq[1 << LETTERS];
int overflow_index = -1;

int get_freq(int index) {
    return ((index == overflow_index) << 16) + freq[index];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string str;
    vector<int> masks(N);

    for (int i = 0; i < N; i++) {
        cin >> str;
        int mask = 0;

        for (char c : str)
            mask ^= 1 << (c - 'a');

        masks[i] = mask;
        freq[mask]++;

        if (freq[mask] == 0)
            overflow_index = mask;
    }

    sort(masks.begin(), masks.end());
    masks.resize(unique(masks.begin(), masks.end()) - masks.begin());
    long long total = 0;

    for (int mask : masks) {
        total += (long long) get_freq(mask) * (get_freq(mask) - 1) / 2;

        for (int i = 0; i < LETTERS; i++)
            if (mask & 1 << i)
                total += (long long) get_freq(mask) * get_freq(mask ^ 1 << i);
    }

    cout << total << '\n';
}