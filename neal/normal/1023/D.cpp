#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int NQ_MAX = 2e5 + 5;

struct range {
    int start, end;

    range() {
        start = NQ_MAX;
        end = -NQ_MAX;
    }
};

int N, Q;
int array[NQ_MAX];
long long tree[NQ_MAX];
range ranges[NQ_MAX];
long long freq[NQ_MAX];
vector<int> positions[NQ_MAX];

void tree_update(int index, int change) {
    for (int i = index + 1; i <= N; i += i & -i)
        tree[i] += change;
}

long long tree_query(int count) {
    long long sum = 0;

    for (int i = count; i > 0; i -= i & -i)
        sum += tree[i];

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        cin >> array[i];

        freq[array[i]]++;
        positions[array[i]].push_back(i);
        ranges[array[i]].start = min(ranges[array[i]].start, i);
        ranges[array[i]].end = max(ranges[array[i]].end, i + 1);
        tree_update(i, array[i]);
    }

    for (int q = Q; q > 0; q--) {
        if (ranges[q].start == NQ_MAX)
            continue;

        long long sum = tree_query(ranges[q].end) - tree_query(ranges[q].start);

        if (sum != q * freq[q]) {
            cout << "NO" << '\n';
            return 0;
        }

        for (int pos : positions[q])
            tree_update(pos, -q);
    }

    bool has_Q = !positions[Q].empty();

    if (!has_Q) {
        bool found = false;

        for (int i = 0; i < N; i++)
            if (array[i] == 0) {
                array[i] = Q;
                found = true;
                break;
            }

        if (!found) {
            cout << "NO" << '\n';
            return 0;
        }
    }

    cout << "YES" << '\n';

    for (int i = 0, j = 0; i < N; i = j) {
        j = i + 1;

        if (array[i] == 0) {
            while (j < N && array[j] == 0)
                j++;

            for (int k = i; k < j; k++) {
                assert(array[k] == 0);
                assert(i > 0 || j < N);
                array[k] = i > 0 ? array[i - 1] : array[j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        assert(array[i] > 0);
        cout << array[i] << (i < N - 1 ? ' ' : '\n');
    }

    return 0;
}