#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

const int INC_OP = 1, DEC_OP = 2, INV_OP = 3;

struct node {
    int dist;
    char prev_op;
};

int U, V, P;

int reverse_op(int op) {
    switch(op) {
        case INC_OP: return DEC_OP;
        case DEC_OP: return INC_OP;
        case INV_OP: return INV_OP;
    }

    return -1;
}

int mod_pow(long long a, int b) {
    long long result = 1;

    while (b > 0) {
        if (b & 1)
            result = result * a % P;

        a = a * a % P;
        b >>= 1;
    }

    return result;
}

int mod_inc(int a) {
    return a == P - 1 ? 0 : a + 1;
}

int mod_dec(int a) {
    return a == 0 ? P - 1 : a - 1;
}

int mod_inv(int a) {
    return mod_pow(a, P - 2);
}

int apply_op(int a, int op) {
    switch(op) {
        case INC_OP: return mod_inc(a);
        case DEC_OP: return mod_dec(a);
        case INV_OP: return mod_inv(a);
    }

    return -1;
}

void bfs_iteration(queue<int> &q, unordered_map<int, node> &number_map, int current_dist) {
    assert(!q.empty());

    while (!q.empty()) {
        int current = q.front();

        if (number_map[current].dist > current_dist)
            return;

        q.pop();

        for (char op = 1; op <= 3; op++) {
            int next = apply_op(current, op);

            if (number_map.find(next) == number_map.end()) {
                number_map[next] = (node) {number_map[current].dist + 1, op};
                q.push(next);
            }
        }
    }
}

int common(unordered_map<int, node> &U_map, unordered_map<int, node> &V_map) {
    for (auto it = U_map.begin(); it != U_map.end(); it++)
        if (V_map.find(it->first) != V_map.end())
            return it->first;

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> U >> V >> P;

    unordered_map<int, node> U_map, V_map;
    queue<int> U_queue, V_queue;

    U_map[U] = (node) {0, -1};
    V_map[V] = (node) {0, -1};
    U_queue.push(U);
    V_queue.push(V);

    int U_dist = 0, V_dist = 0;
    int middle = -1;

    while (true) {
        middle = common(U_map, V_map);

        if (middle != -1)
            break;

        if (U_map.size() < V_map.size())
            bfs_iteration(U_queue, U_map, U_dist++);
        else
            bfs_iteration(V_queue, V_map, V_dist++);
    }

    vector<int> U_ops, V_ops;

    for (int num = middle; num != U; num = apply_op(num, reverse_op(U_map[num].prev_op)))
        U_ops.push_back(U_map[num].prev_op);

    reverse(U_ops.begin(), U_ops.end());

    for (int num = middle; num != V; num = apply_op(num, reverse_op(V_map[num].prev_op)))
        V_ops.push_back(reverse_op(V_map[num].prev_op));

    vector<int> combined;

    for (int op : U_ops)
        combined.push_back(op);

    for (int op : V_ops)
        combined.push_back(op);

    cout << combined.size() << '\n';

    for (int i = 0; i < (int) combined.size(); i++)
        cout << combined[i] << (i < (int) combined.size() - 1 ? ' ' : '\n');

    int number = U;

    for (int op : combined) {
        assert(op == INC_OP || op == DEC_OP || op == INV_OP);
        number = apply_op(number, op);
    }

    assert(number == V);
    return 0;
}