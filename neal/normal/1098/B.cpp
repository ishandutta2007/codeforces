#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;
const string DNA = "ACGT";

int N, M;
vector<string> table;

int best = INF;
vector<string> best_nice;

vector<string> rotate(const vector<string> &v) {
    int rows = v.size();
    int cols = v[0].size();
    vector<string> rotated(cols, string(rows, '.'));

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            rotated[c][r] = v[r][c];

    return rotated;
}

int cost;

int difference(const string &a, const string &b) {
    assert(a.size() == b.size());
    int n = a.size();
    int count = 0;

    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            count++;

    return count;
}

string best_row(const string &row, char first, char second) {
    int n = row.size();
    string candidate1 = "", candidate2 = "";

    for (int i = 0; i < n; i++) {
        candidate1 += i % 2 == 0 ? first : second;
        candidate2 += i % 2 == 0 ? second : first;
    }

    int cost1 = difference(candidate1, row);
    int cost2 = difference(candidate2, row);
    cost += min(cost1, cost2);
    return cost1 < cost2 ? candidate1 : candidate2;
}

void attempt(char first, char second, bool needs_rotate) {
    char third = '\0', fourth = '\0';

    for (int i = 0; i < 4; i++)
        if (DNA[i] != first && DNA[i] != second) {
            if (third == '\0')
                third = DNA[i];
            else
                fourth = DNA[i];
        }

    vector<string> current(N);
    cost = 0;

    for (int i = 0; i < N; i++) {
        current[i] = best_row(table[i], first, second);
        swap(first, third);
        swap(second, fourth);
    }

    if (cost < best) {
        best = cost;
        best_nice = needs_rotate ? rotate(current) : current;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    table.resize(N);

    for (int i = 0; i < N; i++)
        cin >> table[i];

    for (int first = 0; first < 4; first++)
        for (int second = first + 1; second < 4; second++)
            attempt(DNA[first], DNA[second], false);

    table = rotate(table);
    swap(N, M);

    for (int first = 0; first < 4; first++)
        for (int second = first + 1; second < 4; second++)
            attempt(DNA[first], DNA[second], true);

    table = rotate(table);
    swap(N, M);

    cerr << best << '\n';

    for (int i = 0; i < N; i++)
        cout << best_nice[i] << '\n';
}