#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct union_find {
    // When data[x] < 0, x is a root and -data[x] is its tree size. When data[x] >= 0, data[x] is x's parent.
    vector<int> data;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        data.assign(n + 1, -1);
        components = n;
    }

    int find(int x) {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }

    int get_size(int x) {
        return -data[find(x)];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (-data[x] < -data[y])
            swap(x, y);

        data[x] += data[y];
        data[y] = x;
        components--;
        return true;
    }
};


const int BITS = 18;

int freq[1 << BITS];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freq[0] = 1;

    int N;
    cin >> N;
    long long answer = 0;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        freq[a]++;
        answer -= a;
    }

    union_find UF(1 << BITS);

    auto &&contribution = [&](int a, int b) {
        if (freq[a] == 0 || freq[b] == 0 || !UF.unite(a, b))
            return 0;

        int edges = freq[a] + freq[b] - 1;
        freq[a] = freq[b] = 1;
        return edges;
    };

    for (int sum = (1 << BITS) - 1; sum >= 0; sum--)
        for (int mask = sum; mask > (sum ^ mask); mask = (mask - 1) & sum) {
            int other = sum ^ mask;
            int edges = contribution(mask, other);
            answer += (long long) edges * sum;
        }

    cout << answer << '\n';
}