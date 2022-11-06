#include <bits/stdc++.h>

using namespace std;

const int TWO = 512;
const int MOD = 998244353;
const int MAXN = 1E5;
vector<int> adjList[MAXN + 1];
int nim[MAXN + 1];
bool visited[MAXN + 1];
int freq[TWO];

int add(int x, int y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
    if (x < 0)
        x += MOD;
    return x;
}

int modpow(int b, int e)
{
    int ans = 1;
    while (e)
    {
        if (e & 1)
            ans = (int) ((long long) ans * b % MOD);
        b = (int) ((long long) b * b % MOD);
        e >>= 1;
    }
    return ans;
}

int modinv(int x)
{
    return modpow(x, MOD - 2);
}

int dfs(int v, int p)
{
    if (visited[v])
        return nim[v];
    visited[v] = true;
    set<int> seen;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        seen.insert(dfs(adj, v));
    }
    for (auto x : seen)
    {
        if (x == nim[v])
            nim[v]++;
    }
    freq[nim[v]]++;
    return nim[v];
}

void gauss(vector<vector<int>> &mat)
{
    int n = (int) mat.size();
    int m = (int) mat[0].size();
    for (int i = 0; i < n; i++)
    {
        int nonzeroRow = i;
        for (int j = i + 1; j < n; j++)
        {
            if (mat[nonzeroRow][i] == 0 && mat[j][i] != 0)
                nonzeroRow = j;
        }
        for (int j = 0; j < m; j++)
            swap(mat[i][j], mat[nonzeroRow][j]);
        if (mat[i][i] == 0)
            continue;
        int inv = modinv(mat[i][i]);
        for (int j = 0; j < n; j++)
        {
            if (j == i || mat[j][i] == 0)
                continue;
            int mult = (int) ((long long) inv * mat[j][i] % MOD);
            for (int k = 0; k < m; k++)
            {
                //cout << "orig " << mat[j][k] << endl;
                mat[j][k] = add(mat[j][k], -(int) ((long long) mat[i][k] * mult % MOD));
                //cout << "sub " << -(int) ((long long) mat[i][k] * mult % MOD) << endl;
                //cout << mat[j][k] << endl;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (mat[i][i] == 0)
            continue;
        mat[i][m - 1] = (int) ((long long) mat[i][m - 1] * modinv(mat[i][i]) % MOD);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i, i);
    }
    vector<vector<int>> mat(TWO, vector<int>(TWO + 1));
    mat[0][TWO] = modinv(n + 1);
    for (int i = 0; i < TWO; i++)
    {
        mat[i][i] = 1;
        for (int j = 0; j < TWO; j++)
        {
            mat[i][j] = add(mat[i][j], -(int) ((long long) freq[j ^ i] * modinv(n + 1) % MOD));
        }
    }/*
    for (int i = 0; i < TWO; i++)
    {
        for (int j = 0; j < TWO + 1; j++)
        {
            cout << mat[i][j] << " \n"[j == TWO];
        }
    }*/
    gauss(mat);
    /*for (int i = 0; i < TWO; i++)
    {
        for (int j = 0; j < TWO + 1; j++)
        {
            cout << mat[i][j] << " \n"[j == TWO];
        }
    }*/
    cout << add(1, -mat[0][TWO]) << "\n";
    return 0;
}