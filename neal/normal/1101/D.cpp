#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 2);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (long long p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);

            for (long long i = p * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}


const int A_MAX = 2e5 + 5;

int N;
vector<vector<pair<int, int>>> factor_list;
vector<vector<int>> adj;
int longest;

const vector<pair<int, int>> &extend(const vector<pair<int, int>> &root) {
    return root;
}

void attach(vector<pair<int, int>> &root, const vector<pair<int, int>> &child) {
    int c = 0;

    for (pair<int, int> &p : root)
        while (c < (int) child.size() && child[c].first <= p.first) {
            if (child[c].first == p.first) {
                longest = max(longest, p.second + child[c].second);
                p.second = max(p.second, child[c].second + 1);
            }

            c++;
        }
}

vector<pair<int, int>> dfs(int node, int parent) {
    vector<pair<int, int>> answer = factor_list[node];

    if (!answer.empty())
        longest = max(longest, 1);

    for (int neighbor : adj[node])
        if (neighbor != parent) {
            vector<pair<int, int>> child = dfs(neighbor, node);
            attach(answer, extend(child));
        }

    return answer;
}

int main() {
    sieve(A_MAX);
    scanf("%d", &N);
    factor_list.assign(N, {});
    adj.assign(N, {});

    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);

        while (a != 1) {
            int p = smallest_factor[a];

            do {
                a /= p;
            } while (a % p == 0);

            factor_list[i].emplace_back(p, 1);
        }
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);
    printf("%d\n", longest);
}