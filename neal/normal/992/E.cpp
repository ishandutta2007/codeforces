// http://codeforces.com/contest/992/problem/E
#include <iostream>
using namespace std;

const int N_MAX = 2e5 + 5;

int N, Q;
int power[N_MAX];
long long tree[N_MAX];

long long tree_sum(int index) {
    long long sum = 0;

    for (int i = index; i > 0; i -= i & -i)
        sum += tree[i];

    return sum;
}

void tree_update(int index, int change) {
    for (int i = index; i <= N; i += i & -i)
        tree[i] += change;
}

// Finds the first index x such that tree_sum(x) >= sum.
int find_first(long long sum) {
    // Find the last index x such that tree_sum(x) < sum, and then add one.
    int index = 0;
    int k = 0;

    while (1 << (k + 1) <= N)
        k++;

    while (k >= 0) {
        int next_index = index + (1 << k);

        if (next_index <= N && tree[next_index] < sum) {
            index = next_index;
            sum -= tree[index];
        }

        k--;
    }

    return index + 1;
}

int query() {
    long long sum = 0;

    while (true) {
        int index = find_first(2 * sum);

        if (index > N)
            return -1;

        sum = tree_sum(index);

        if (2 * power[index] == sum)
            return index;
    }
}

int main() {
    scanf("%d %d", &N, &Q);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &power[i]);
        tree_update(i, power[i]);
    }

    for (int q = 0; q < Q; q++) {
        int index, value;
        scanf("%d %d", &index, &value);
        tree_update(index, value - power[index]);
        power[index] = value;
        printf("%d\n", query());
    }

    return 0;
}