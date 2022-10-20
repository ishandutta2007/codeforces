#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 2020;

int n;
int matrix[N][N], far[N];
long long d[N][N];
vector <pair <int, long long> > a[N];
vector < pair<long long, pair<int, int> > > ds;

int Getfar(int x) {
    return (far[x] == x)? x : (far[x] = Getfar(far[x]));
}

void DFS(int root, int u, int p) {
    for(int i = 0; i < (int)a[u].size(); i++) {
        int v = a[u][i].first;
        if(v != p) {
            long long x = a[u][i].second;
            d[root][v] = d[root][u] + x;
            DFS(root, v, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
        cin >> matrix[i][j];
        if(i != j && !matrix[i][j]) {
            cout << "NO";
            return 0;
        }
        if(i == j && matrix[i][j]) {
            cout << "NO";
            return 0;
        }
        if(i < j)  ds.push_back(make_pair(matrix[i][j], make_pair(i, j)));
    }
    for(int i = 1; i <= n; i++) far[i] = i;
    sort(ds.begin(), ds.end());
    for(int i = 0; i < (int)ds.size(); i++) {
        int u = ds[i].second.first, v = ds[i].second.second;
        long long dd = ds[i].first;
        int r1 = Getfar(u);
        int r2 = Getfar(v);
        if(r1 != r2) {
            a[u].push_back(make_pair(v, dd));
            a[v].push_back(make_pair(u, dd));
            far[r1] = r2;
        }
    }
    for(int i = 1; i <= n; i++) DFS(i, i, 0);
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    if(matrix[i][j] != d[i][j]) {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}