#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;
const long long LL_INF = (long long) 2e18 + 5;

struct voter {
    int M, P;

    bool operator<(const voter &other) const {
        return M < other.M;
    }
};

int N;
vector<voter> voters;

long long evaluate(int buy) {
    int index = 0;
    priority_queue<int> pq;

    for (int position = buy; position < N; position++) {
        while (index < N && voters[index].M <= position)
            pq.push(voters[index++].P);

        if (pq.empty())
            return LL_INF - buy;

        pq.pop();
    }

    while (index < N)
        pq.push(voters[index++].P);

    long long sum = 0;

    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }

    return sum;
}

void solve_case() {
    cin >> N;
    voters.resize(N);

    for (voter &v : voters)
        cin >> v.M >> v.P;

    sort(voters.begin(), voters.end());
    int low = 0, high = N;

    while (low < high) {
        int mid = (low + high) / 2;

        if (evaluate(mid) < evaluate(mid + 1))
            high = mid;
        else
            low = mid + 1;
    }

    cout << evaluate(low) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}