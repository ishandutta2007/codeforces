#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int N = 2e5;

int depth[N];
int higest_vertex_in_the_chain[N], lowest_vertex_in_the_chain[N], order[N], pos_in_list[N];
int all[N], number_of_vertexes;
vector <int> edges[N];
int all_tree[4 * N], all_tree_push[4 * N];
int chain_tree[4 * N], chain_tree_push[4 * N];
int max_depth;
int last_in_list[N];
bool used[N];
queue <int> q;

void count_depth_and_order(int x, int pred, int dp) {
    order[x] = ++number_of_vertexes;
    depth[order[x]] = dp;
    max_depth = max(max_depth, dp);
    for (size_t i = 0; i < edges[x].size(); i++) {
        int to = edges[x][i];
        if (pred == to) {
            continue;
        }
        count_depth_and_order(to, x, dp + 1);
    }
}

int find_deepest_in_the_chain(int x, int pred) {
    for (size_t i = 0; i < edges[x].size(); i++) {
        int to = edges[x][i];
        if (to == pred) {
            continue;
        }
        return find_deepest_in_the_chain(to, x);
    }
    return order[x];
}

void build_borders(int x, int pred, int highest, int lowest) {
    higest_vertex_in_the_chain[order[x]] = highest;
    lowest_vertex_in_the_chain[order[x]] = lowest;
    for (size_t i = 0; i < edges[x].size(); i++) {
        int to = edges[x][i];
        if (to == pred) {
            continue;
        }
        build_borders(to, x, highest, lowest);
    }
}

void push_all(int i) {
    all_tree_push[i * 2] += all_tree_push[i];
    all_tree_push[i * 2 + 1] += all_tree_push[i];
    all_tree[i * 2] += all_tree_push[i];
    all_tree[i * 2 + 1] += all_tree_push[i];
    all_tree_push[i] = 0;
}

int get_all(int i, int l, int r, int d) {
    if (l == r) {
        return all_tree[i];
    }
    push_all(i);
    int m = (l + r) / 2;
    if (d <= m) {
        return get_all(i * 2, l, m, d);
    } else {
        return get_all(i * 2 + 1, m + 1, r, d);
    }
}

void modify_all(int i, int l, int r, int ql, int qr, int x) {
    if (l == ql && r == qr) {
        all_tree[i] += x;
        all_tree_push[i] += x;
        return;
    }
    push_all(i);
    int m = (l + r) / 2;
    if (ql <= m) {
        modify_all(i * 2, l, m, ql, min(qr, m), x);
    }
    if (m < qr) {
        modify_all(i * 2 + 1, m + 1, r, max(ql, m + 1), qr, x);
    }
}

void push_chain(int i) {
    chain_tree_push[i * 2] += chain_tree_push[i];
    chain_tree_push[i * 2 + 1] += chain_tree_push[i];
    chain_tree[i * 2] += chain_tree_push[i];
    chain_tree[i * 2 + 1] += chain_tree_push[i];
    chain_tree_push[i] = 0;
}

int get_chain(int i, int l, int r, int d) {
    if (l == r) {
        return chain_tree[i];
    }
    push_chain(i);
    int m = (l + r) / 2;
    if (d <= m) {
        return get_chain(i * 2, l, m, d);
    } else {
        return get_chain(i * 2 + 1, m + 1, r, d);
    }
}

void modify_chain(int i, int l, int r, int ql, int qr, int x) {
    if (l == ql && r == qr) {
        chain_tree[i] += x;
        chain_tree_push[i] += x;
        return;
    }
    push_chain(i);
    int m = (l + r) / 2;
    if (ql <= m) {
        modify_chain(i * 2, l, m, ql, min(qr, m), x);
    }
    if (m < qr) {
        modify_chain(i * 2 + 1, m + 1, r, max(ql, m + 1), qr, x);
    }
}

int main() {
    int number, quests;
    scanf("%d %d", &number, &quests);
    for (int i = 1; i < number; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    number_of_vertexes = 0;
    count_depth_and_order(1, 1, 0);
    for (size_t i = 0; i < edges[1].size(); i++) {
        int to = edges[1][i];
        int deepest = find_deepest_in_the_chain(to, 1);
        build_borders(to, 1, order[to], deepest);
    }
    number_of_vertexes = 0;
    q.push(1);
    used[1] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int x = order[cur];
        number_of_vertexes++;
        all[number_of_vertexes] = x;
        pos_in_list[x] = number_of_vertexes;
        last_in_list[depth[x]] = max(last_in_list[depth[x]], pos_in_list[x]);
        for (size_t i = 0; i < edges[cur].size(); i++) {
            int to = edges[cur][i];
            if (used[to]) {
                continue;
            }
            used[to] = true;
            q.push(to);
        }
    }
    for (int q_cur = 1; q_cur <= quests; q_cur++) {
        int type;
        scanf("%d", &type);
        if (type == 0) {
            int v, x, d;
            scanf("%d %d %d", &v, &x, &d);
            v = order[v];
            if (v == 1) {
                d = min(d, max_depth);
                modify_all(1, 1, number_of_vertexes, 1, last_in_list[d], x);
            } else {
                int highest = max(v - d, higest_vertex_in_the_chain[v]);
                int lowest = min(v + d, lowest_vertex_in_the_chain[v]);
                modify_chain(1, 1, number_of_vertexes, highest, lowest, x);
                if (depth[v] > d) {
                    continue;
                }
                if (depth[v] == d) {
                    modify_all(1, 1, number_of_vertexes, 1, 1, x);
                    continue;
                }
                d -= depth[v];
                d = min(d, max_depth);
                modify_all(1, 1, number_of_vertexes, 1, last_in_list[d], x);
                lowest = min(lowest_vertex_in_the_chain[v], highest + d - 1);
                modify_chain(1, 1, number_of_vertexes, highest, lowest, -x);
            }
            
        } else {
            int v;
            scanf("%d", &v);
            v = order[v];
            int res = 0;
            res += get_all(1, 1, number_of_vertexes, pos_in_list[v]);
            res += get_chain(1, 1, number_of_vertexes, v);
            printf("%d\n", res);
        }
    }
    return 0;
}