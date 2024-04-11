#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

string get_goal(const string &a, const string &b) {
    string goal;

    for (int i = 0; i < (int) a.size(); i++)
        if (a[i] == b[i])
            goal += a[i];
        else
            goal += 'S' + 'E' + 'T' - a[i] - b[i];

    return goal;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<string> cards(N);
    gp_hash_table<string, null_type> cards_set;

    for (string &card : cards) {
        cin >> card;
        cards_set.insert(card);
    }

    int total = 0;

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) {
            string goal = get_goal(cards[i], cards[j]);
            total += cards_set.find(goal) != cards_set.end();
        }

    assert(total % 3 == 0);
    cout << total / 3 << '\n';
}