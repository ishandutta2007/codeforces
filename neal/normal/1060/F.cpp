#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<double>> choose;
vector<vector<int>> adj;

void precompute() {
    choose.resize(N + 1);

    for (int i = 0; i <= N; i++) {
        choose[i].resize(i + 1);
        choose[i][0] = 1;

        for (int j = 1; j <= i; j++)
            choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
    }
}

vector<double> extend(const vector<double> &a) {
    int n = a.size();
    vector<double> b(n + 1, 0);
    double sum = 0;

    for (int i = 0; i <= n; i++) {
        b[i] = (sum + (n - i) * a[i]) / n;
        sum += 0.5 * a[i];
    }

    return b;
}

vector<double> merge(const vector<double> &a, const vector<double> &b) {
    int n = a.size() - 1, m = b.size() - 1;
    vector<double> c(n + m + 1, 0);

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            c[i + j] += choose[i + j][i] * choose[n - i + m - j][n - i] * a[i] * b[j];

    for (double &p : c)
        p /= choose[n + m][n];

    return c;
}

vector<double> solve(int node, int parent) {
    vector<double> answer(1, 1);

    for (int neighbor : adj[node])
        if (neighbor != parent) {
            vector<double> neighbor_answer = solve(neighbor, node);
            answer = merge(answer, extend(neighbor_answer));
        }

    return answer;
}

int main() {
    scanf("%d", &N);
    precompute();
    adj.assign(N, vector<int>());

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < N; i++)
        printf("%.10lf\n", solve(i, -1).back());
}