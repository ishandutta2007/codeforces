#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };

struct safe_hash32 {
    static unsigned hash32(unsigned x) {
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        return x ^ (x >> 16);
    }

    unsigned operator()(unsigned x) const {
        static const unsigned FIXED_RANDOM = hash32(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));
        return hash32(x ^ FIXED_RANDOM);
    }
};


using hash_t = uint8_t;

const int INF = 1e9 + 5;

struct lecture {
    int start, end, index;

    bool operator<(const lecture &other) const {
        return make_pair(start, end) < make_pair(other.start, other.end);
    }
};

int N;
vector<lecture> A, B;
vector<hash_t> hash_value;

vector<hash_t> compute_hashes(vector<lecture> lectures) {
    sort(lectures.begin(), lectures.end());
    vector<hash_t> prefix_sums(N + 1, 0);

    for (int i = 0; i < N; i++)
        prefix_sums[i + 1] = prefix_sums[i] + hash_value[lectures[i].index];

    vector<hash_t> answers(N, 0);
    vector<hash_t> changes(N + 1, 0);

    for (int i = 0; i < N; i++) {
        int end = lower_bound(lectures.begin(), lectures.end(), (lecture) {lectures[i].end, INF, -1}) - lectures.begin();
        answers[i] += prefix_sums[end] - prefix_sums[i + 1];

        // Add current hash value to the range [i + 1, end).
        changes[i + 1] += hash_value[lectures[i].index];
        changes[end] -= hash_value[lectures[i].index];
    }

    hash_t sum = 0;

    for (int i = 0; i < N; i++) {
        sum += changes[i];
        answers[i] += sum;
    }

    vector<hash_t> reordered(N);

    for (int i = 0; i < N; i++)
        reordered[lectures[i].index] = answers[i];

    return reordered;
}

bool check() {
    return compute_hashes(A) == compute_hashes(B);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);
    B.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i].start >> A[i].end >> B[i].start >> B[i].end;
        A[i].index = B[i].index = i;
    }

    hash_value.assign(N, 0);

    for (int i = 0; i < N; i++)
        hash_value[i] = safe_hash32()(i);

    cout << (check() ? "YES" : "NO") << '\n';
}