// Solution to https://codeforces.com/contest/13/problem/E
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int N, M, BUCKET_SIZE;
vector<int> power;
vector<int> jump_to, jump_count;

int get_bucket_start(int index) {
    return index - index % BUCKET_SIZE;
}

int get_bucket_end_from_start(int bucket_start) {
    return min(bucket_start + BUCKET_SIZE, N);
}

void compute_jump(int index) {
    int bucket_start = get_bucket_start(index);
    int bucket_end = get_bucket_end_from_start(bucket_start);
    int reach = index + power[index];

    if (reach >= N) {
        jump_to[index] = index;
        jump_count[index] = 0;
    } else if (reach >= bucket_end) {
        jump_to[index] = reach;
        jump_count[index] = 1;
    } else {
        jump_to[index] = jump_to[reach];
        jump_count[index] = jump_count[reach] + 1;
    }
}

void update_power(int a, int b) {
    int bucket_start = get_bucket_start(a);
    power[a] = b;

    for (int i = a; i >= bucket_start; i--)
        compute_jump(i);
}

pair<int, int> query(int a) {
    int count = 1;

    while (a != jump_to[a]) {
        count += jump_count[a];
        a = jump_to[a];
    }

    return {a, count};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    BUCKET_SIZE = 1.2 * sqrt(N) + 1;
    cerr << "Bucket size: " << BUCKET_SIZE << endl;
    power.resize(N);
    jump_to.resize(N);
    jump_count.resize(N);

    for (int i = 0; i < N; i++)
        cin >> power[i];

    for (int i = N - 1; i >= 0; i--)
        compute_jump(i);

    for (int i = 0; i < M; i++) {
        int type, a, b;
        cin >> type >> a;
        a--;

        if (type == 0) {
            cin >> b;
            update_power(a, b);
        } else if (type == 1) {
            pair<int, int> answer = query(a);
            cout << answer.first + 1 << ' ' << answer.second << '\n';
        } else {
            assert(false);
        }
    }
}