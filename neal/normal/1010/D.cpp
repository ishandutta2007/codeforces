#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int IN = 0, AND = 1, OR = 2, XOR = 3, NOT = 4;

struct node {
    int operation;
    int x, y;
    int value;

    node() : operation(-1), x(-1), y(-1), value(-1) {}
};

int N;
vector<node> tree;
vector<int> parent;
vector<int> usual;
vector<int> dp[2];

int operation_to_int(const string &str) {
    if (str == "IN")
        return IN;
    else if (str == "AND")
        return AND;
    else if (str == "OR")
        return OR;
    else if (str == "XOR")
        return XOR;
    else if (str == "NOT")
        return NOT;

    assert(false);
}

int get(int index, int changed_index, int changed_value) {
    return index == changed_index ? changed_value : usual[index];
}

int compute(int index, int child = -1, int changed_value = -1) {
    if (tree[index].operation == IN)
        return get(index, child, changed_value);
    else if (tree[index].operation == AND)
        return get(tree[index].x, child, changed_value) && get(tree[index].y, child, changed_value);
    else if (tree[index].operation == OR)
        return get(tree[index].x, child, changed_value) || get(tree[index].y, child, changed_value);
    else if (tree[index].operation == XOR)
        return get(tree[index].x, child, changed_value) ^ get(tree[index].y, child, changed_value);
    else if (tree[index].operation == NOT)
        return !get(tree[index].x, child, changed_value);

    assert(false);
}

int solve(int index, int value) {
    if (index == 1)
        return value;

    int &answer = dp[value][index];

    if (answer != -1)
        return answer;

    int p = parent[index];
    int next_value = compute(p, index, value);
    return answer = solve(p, next_value);
}

void compute_usual(int index) {
    if (tree[index].operation == IN) {
        usual[index] = tree[index].value;
        return;
    }

    if (tree[index].x != -1)
        compute_usual(tree[index].x);

    if (tree[index].y != -1)
        compute_usual(tree[index].y);

    usual[index] = compute(index);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    parent.resize(N + 1, -1);
    tree.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        string str;
        cin >> str;
        tree[i].operation = operation_to_int(str);

        if (tree[i].operation == IN) {
            cin >> tree[i].value;
        } else if (tree[i].operation == NOT) {
            cin >> tree[i].x;
            parent[tree[i].x] = i;
        } else {
            cin >> tree[i].x >> tree[i].y;
            parent[tree[i].x] = parent[tree[i].y] = i;
        }
    }

    usual.resize(N + 1, -1);
    compute_usual(1);

    for (int c = 0; c < 2; c++)
        dp[c].resize(N + 1, -1);

    string answer = "";

    for (int i = 1; i <= N; i++)
        if (tree[i].operation == IN)
            answer += solve(i, !usual[i]) + '0';

    cout << answer << '\n';
    return 0;
}