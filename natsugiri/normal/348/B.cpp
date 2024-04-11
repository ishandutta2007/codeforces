#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

typedef long long LL;
typedef vector<vector<int> > Mat;
const LL INF  = 1LL<<60;

LL gcd(LL a, LL b) {
    while (b) {
	a %= b;
	swap(a, b);
    }
    return a;
}
LL lcm(LL a, LL b) {
    return a/gcd(a, b)*b;
}

int N;
LL A[100010];
LL rate[100010];
Mat G;
LL ans;

void dfs(int v, int p) {
    int ch=0;
    rate[v] = 1;
    double lcm = 1;
    bool zero=false;
    
    for (int i=0; i<int(G[v].size()); i++) {
	if (G[v][i] == p) continue;
	ch++;
	dfs(G[v][i], v);
	LL g = gcd(rate[v], rate[G[v][i]]);
	if (g<=0) { zero = true; g=1; }
	rate[v] = rate[v]/g*rate[G[v][i]];
	lcm = lcm/g*rate[G[v][i]];
	if (A[G[v][i]]==0) zero = true;
    }

    //printf("%d %lld\n", v, rate[v]);
    if (ch==0) return;

    if (lcm > 1e9) zero = true;
    
    LL mi = INF;
    if (zero || rate[v] == 0) {
	rate[v] = 1;
	mi = 0;
    }
    for (int i=0; i<int(G[v].size()); i++) {
	if (G[v][i] == p) continue;
	mi = min(mi, A[G[v][i]] - A[G[v][i]] % rate[v]);
    }

    for (int i=0; i<int(G[v].size()); i++) {
	if (G[v][i] == p) continue;
	ans += A[G[v][i]] - mi;
    }
    rate[v] *= ch;
    A[v] = mi * ch;
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) cin >> A[i];

    G = Mat(N);
    for (int i=1; i<N; i++) {
	int a, b;
	scanf("%d%d", &a, &b); a--; b--;
	G[a].push_back(b);
	G[b].push_back(a);
    }

    dfs(0, -1);
    cout << ans << endl;
    return 0;
}