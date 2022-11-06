#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int nodes[MAXN + 1];
vector<int> adjList[MAXN + 1];
int isPrime[MAXN + 1];
vector<int> primes;
bool visited[MAXN + 1];
vector<pair<int, int>> dp[MAXN + 1];

int solve(int root, int parent)
{
    int ans = 0;
    for (int adj : adjList[root])
    {
        if (adj != parent)
        {
            ans = max(ans, solve(adj, root));
        }
    }
    for (int i = 0; i < (int) dp[root].size(); i++)
    {
        int prime = dp[root][i].first;
        vector<int> st;
        st.push_back(0);
        st.push_back(0);
        for (int adj : adjList[root])
        {
            if (adj == parent)
                continue;
            for (int j = 0; j < (int) dp[adj].size(); j++)
            {
                if (dp[adj][j].first == prime)
                {
                    int chain = dp[adj][j].second;
                    if (chain > st.back())
                    {
                        st.pop_back();
                        if (chain > st.back())
                        {
                            int temp = st.back();
                            st.pop_back();
                            st.push_back(chain);
                            st.push_back(temp);
                        }
                        else
                        {
                            st.push_back(chain);
                        }
                    }
                }
            }
        }
        ans = max(ans, 1 + st[0] + st[1]);
    }
    return ans;
}

void dfs(int root, int parent)
{
    for (int adj : adjList[root])
    {
        if (adj != parent)
        {
            dfs(adj, root);
        }
    }
    int x = nodes[root];
    while (x > 1)
    {
        int prime = isPrime[x];
        while (x % prime == 0)
            x /= prime;
        int chain = 1;
        for (int adj : adjList[root])
        {
            if (adj != parent)
            {
                for (int j = 0; j < (int) dp[adj].size(); j++)
                {
                    if (dp[adj][j].first == prime)
                    {
                        chain = max(chain, dp[adj][j].second + 1);
                    }
                }
            }
        }
        dp[root].push_back({prime, chain});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i <= MAXN; i++)
    {
        if (isPrime[i] == 0)
        {
            primes.push_back(i);
            for (int j = i; j <= MAXN; j += i)
            {
                isPrime[j] = i;
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nodes[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    dfs(1, 0);
    /*
    cout << "test" << endl;
    for (pair<int, int> pr : dp[3])
    {
        cout << pr.first << " " << pr.second << endl;
    }
    */
    cout << solve(1, 0) << endl;
    return 0;
}