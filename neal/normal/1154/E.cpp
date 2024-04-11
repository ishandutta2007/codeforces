#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct link {
    link *prev, *next;
    int value, index;

    link(link *_prev = nullptr, link *_next = nullptr, int _value = -1, int _index = -1)
        : prev(_prev), next(_next), value(_value), index(_index) {}
};

int N, K;
vector<int> A;
vector<link *> where;
vector<int> answers;

pair<link *, link *> erase(link *node) {
    if (node->prev != nullptr)
        node->prev->next = node->next;

    if (node->next != nullptr)
        node->next->prev = node->prev;

    where[node->value] = nullptr;
    return {node->prev, node->next};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    A.resize(N);
    where.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        where[A[i]] = new link(nullptr, nullptr, A[i], i);
    }

    for (int i = 0; i + 1 < N; i++) {
        where[A[i]]->next = where[A[i + 1]];
        where[A[i + 1]]->prev = where[A[i]];
    }

    answers.resize(N);
    int team = 1;

    for (int a = N - 1; a >= 0; a--) {
        if (where[a] == nullptr)
            continue;

        link *current = where[a]->next;

        for (int j = 1; j <= K && current != nullptr; j++) {
            answers[current->index] = team;
            current = erase(current).second;
        }

        current = where[a];

        for (int j = 0; j <= K && current != nullptr; j++) {
            answers[current->index] = team;
            current = erase(current).first;
        }

        team = 3 - team;
    }

    for (int i = 0; i < N; i++)
        cout << answers[i];

    cout << '\n';
}