#include <bits/stdc++.h>
using namespace std;

int N, M, A[200005], dp[200005], prev1[200005];
bool undo[200005];
vector<int> V[200005], factors[200005];


// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y);
 
// Function to find modulo inverse of a
int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1) {
        //cout << "Inverse doesn't exist";
        return 0;
	}
    else
    {
        // m is added to handle negative x
        int res = (x%m + m) % m;
        return res;
    }
}
 
// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

vector<int> v;

void dfs(int x) {
	if (prev1[x] != -1) dfs(prev1[x]);
	for (int i = 0; i < V[x].size(); i++) v.push_back(V[x][i]);
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) undo[A[i]] = 1;
	for (int i = 1; i < M; i++) {
		if (undo[i]) continue;
		V[__gcd(M, i)].push_back(i);
	}
	for (int i = 1; i < M; i++) {
		for (int j = i*2; j < M; j += i) factors[j].push_back(i);
	}
	memset(prev1, -1, sizeof(prev1));
	int ans = -1, best = 0;
	for (int i = 1; i < M; i++) {
		dp[i] = V[i].size();
		int mx = 0;
		for (int j = 0; j < factors[i].size(); j++) {
			if (dp[factors[i][j]] >= mx) {
				mx = dp[factors[i][j]];
				prev1[i] = factors[i][j];
			}
		}
		dp[i] += mx;
		if (dp[i] > ans){ 
			ans = dp[i];
			best = i;
		}
	}
	dfs(best);
	if (!undo[0]) v.push_back(0); 
	long long cur = 1;
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		if (i) printf(" ");
		long long meow = __gcd((long long)cur, (long long)M);
		long long ainv = modInverse(cur/meow, M/meow);
		printf("%lld", ((long long)(v[i]/meow) * ainv) % M);
		cur = v[i];
	}
	printf("\n");
}