#include <iostream>
#include <vector>
using namespace std;

const long long M = 10004205361450474LL;
const long long K_MAX = 10000;
const int QUERIES = 5;

long long high_range_save[QUERIES + 1][K_MAX];

long long iterated(int queries, long long k) {
    return queries == 0 ? 0 : iterated(queries - 1, k) * (k + 1) + k;
}

long long high_range(long long low, int queries) {
    if (queries == 0)
        return low;

    if (low >= K_MAX)
        return low + iterated(queries, K_MAX);

    long long &answer = high_range_save[queries][low];

    if (answer > 0)
        return answer;

    long long next = high_range(low, queries - 1);

    for (int i = 0; i < low; i++)
        next = high_range(next + 1, queries - 1);

    return answer = next;
}

vector<long long> solve(long long low, long long high, int queries) {
    vector<long long> values;
    long long next = high_range(low, queries - 1);

    while (next <= high) {
        values.push_back(next);
        next = high_range(next + 1, queries - 1);
    }

    return values;
}

int query(vector<long long> sequence) {
    cout << sequence.size();

    for (long long x : sequence)
        cout << ' ' << x;

    cout << endl;
    int answer;
    cin >> answer;
    return answer;
}

int main() {
    long long low = 1, high = M, q = QUERIES;

    while (q > 0) {
        vector<long long> values = solve(low, high, q--);
        int answer = query(values);

        if (answer < 0)
            return 0;

        if (answer > 0)
            low = values[answer - 1] + 1;

        if (answer < (int) values.size())
            high = values[answer] - 1;
    }

    return 0;
}