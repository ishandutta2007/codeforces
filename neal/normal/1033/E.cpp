#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<vector<bool>> adj_matrix;

map<vector<int>, int> query_save;
int queries = 0;

int query(vector<int> v) {
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    int size = v.size();

    if (size <= 1)
        return 0;

    if (query_save.find(v) != query_save.end())
        return query_save[v];

    queries++;

#ifdef LOCAL
    int count = 0;

    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            count += adj_matrix[v[i]][v[j]];

    return query_save[v] = count;
#endif

    cout << "? " << size << '\n';

    for (int i = 0; i < size; i++)
        cout << v[i] + 1 << (i < size - 1 ? ' ' : '\n');

    cout << flush;
    int result;
    cin >> result;

    if (result == -1)
        exit(0);

    return query_save[v] = result;
}

vector<int> combine(vector<int> v1, const vector<int> &v2) {
    v1.insert(v1.end(), v2.begin(), v2.end());
    return v1;
}

int between(vector<int> v1, vector<int> v2) {
    return query(combine(v1, v2)) - query(v1) - query(v2);
}

int N;
vector<bool> finished;
vector<vector<int>> levels;
int R;
vector<int> level;
vector<int> remaining;
vector<int> next_level;

void find_next_level(int r_start, int r_end) {
    vector<int> section(remaining.begin() + r_start, remaining.begin() + r_end);
    int edges = between(level, section);

    if (edges == 0)
        return;

    if (r_end - r_start <= 1 || edges == (int) level.size() * (r_end - r_start)) {
        for (int i = r_start; i < r_end; i++)
            next_level.push_back(remaining[i]);

        return;
    }

    int r_mid = (r_start + r_end) / 2;
    find_next_level(r_start, r_mid);
    find_next_level(r_mid, r_end);
}

vector<int> find_path_to_root(int node) {
    vector<int> path(1, node);
    int L = levels.size();

    for (int i = L - 1; i >= 0; i--) {
        bool found = false;

        for (int neighbor : levels[i])
            if (between({node}, {neighbor}) != 0) {
                found = true;
                node = neighbor;
                path.push_back(node);
                break;
            }

        assert(found);
    }

    return path;
}

vector<int> find_actual_cycle() {
    int n = next_level.size();
    assert(n >= 2);
    assert(query(next_level) != 0);
    int index = -1;

    for (int i = 1; i < n; i++) {
        vector<int> prefix(next_level.begin(), next_level.begin() + i);

        if (between({next_level[i]}, prefix) != 0) {
            index = i;
            break;
        }
    }

    assert(index != -1);
    int other = -1;

    for (int i = 0; i < index; i++)
        if (between({next_level[i]}, {next_level[index]}) != 0) {
            other = i;
            break;
        }

    assert(other != -1);
    vector<int> path1 = find_path_to_root(next_level[index]);
    vector<int> path2 = find_path_to_root(next_level[other]);
    assert(path1.size() == path2.size());
    int P = path1.size();
    int same = -1;

    for (int i = 0; i < P; i++)
        if (path1[i] == path2[i]) {
            same = i;
            break;
        }

    assert(same != -1);
    vector<int> cycle;

    for (int i = 0; i < same; i++)
        cycle.push_back(path1[i]);

    for (int i = same; i >= 0; i--)
        cycle.push_back(path2[i]);

    return cycle;
}

int main() {
    cin >> N;

#ifdef LOCAL
    adj_matrix.assign(N, vector<bool>(N, false));
    int a, b;

    while (cin >> a >> b) {
        a--; b--;
        adj_matrix[a][b] = adj_matrix[b][a] = true;
    }
#endif

    finished.assign(N, false);
    levels.push_back({0});

    while (true) {
        level = levels.back();

        for (int node : level)
            finished[node] = true;

        remaining.clear();

        for (int i = 0; i < N; i++)
            if (!finished[i])
                remaining.push_back(i);

        R = remaining.size();

        if (R == 0 || between(level, remaining) == 0)
            break;

        next_level.clear();
        find_next_level(0, R);

        if (query(next_level) != 0) {
            vector<int> cycle = find_actual_cycle();
            int C = cycle.size();
            assert(C % 2 == 1);
            cout << 'N' << ' ' << C << endl;

            for (int i = 0; i < C; i++)
                cout << cycle[i] + 1 << (i < C - 1 ? ' ' : '\n');

            cout << flush;
#ifdef LOCAL
            cerr << queries << " queries" << endl;
#endif
            return 0;
        }

        levels.push_back(next_level);
    }

    vector<int> half;

    for (int i = 0; i < (int) levels.size(); i += 2)
        half.insert(half.end(), levels[i].begin(), levels[i].end());

    sort(half.begin(), half.end());
    int H = half.size();
    cout << 'Y' << ' ' << H << endl;

    for (int i = 0; i < H; i++)
        cout << half[i] + 1 << (i < H - 1 ? ' ' : '\n');

    cout << flush;
#ifdef LOCAL
    cerr << queries << " queries" << endl;
#endif
}