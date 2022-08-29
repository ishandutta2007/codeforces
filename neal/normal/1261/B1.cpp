#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

// WARNING: functions as a set (doesn't allow duplicates); insert pairs instead if duplicates are needed.
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct query {
    int k, pos, index;

    bool operator<(const query &other) const {
        return k < other.k;
    }
};

int N, M;
vector<int> A;
vector<pair<int, int>> sorted;
vector<query> queries;
vector<int> answers;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    for (int i = 0; i < N; i++)
        sorted.emplace_back(-A[i], i);

    sort(sorted.begin(), sorted.end());
    cin >> M;
    queries.resize(M);

    for (query &qry : queries) {
        cin >> qry.k >> qry.pos;
        qry.pos--;
    }

    for (int q = 0; q < M; q++)
        queries[q].index = q;

    sort(queries.begin(), queries.end());
    answers.resize(M);
    ordered_set<pair<int, int>> ordered;
    int index = 0;

    for (query &qry : queries) {
        while (index < qry.k) {
            ordered.insert({sorted[index].second, sorted[index].first});
            index++;
        }

        answers[qry.index] = ordered.find_by_order(qry.pos)->second;
    }

    for (int q = 0; q < M; q++)
        cout << -answers[q] << '\n';
}