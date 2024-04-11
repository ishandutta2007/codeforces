#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
typedef long long ll;

int n, m, q, T, len[N], S[N], c[N], dfn[N], cur;
ll ans[N];
char s[N];
int ch[N][27], fail[N], fa[N], ed[N], tot = 1;
queue <int> Q;
vector <int> G[N];
vector <pair<int,int> > L[N], R[N], le[N], ri[N];

void dfs1(int x) {
	for(auto i : G[x])
		dfs1(i), S[x] += S[i]; 
}

void dfs2(int x) {
	dfn[x] = ++cur, S[x] = 1;
	for(auto i : G[x])
		dfs2(i),  S[x] += S[i];
}

void add(int x, int v) {
	for(; x <= cur; x += x & (-x)) c[x] += v;
}

int ask(int x) {
	int ret = 0;
	for(; x != 0; x -= x & (-x)) ret += c[x];
	return ret;
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) {
		scanf("%s" , s + 1) , len[i] = strlen(s + 1) , m += len[i];
		int p = 1;
		for(int j = 1; j <= len[i]; j++) {
			int c = s[j] - 'a';
			if(!ch[p][c]) ch[p][c] = ++tot, fa[tot] = p;
			p = ch[p][c];
		}
		ed[i] = p;
	}
	for(int i = 0; i < 26; i++) {
		if(ch[1][i]) fail[ch[1][i]] = 1 , Q.push(ch[1][i]);
		else ch[1][i] = 1;
	}
	while(!Q.empty()) {
		int p = Q.front(); Q.pop();
		for(int i = 0; i < 26; i++) {
			if(ch[p][i]) fail[ch[p][i]] = ch[fail[p]][i] , Q.push(ch[p][i]);
			else ch[p][i] = ch[fail[p]][i];
		}
	}
	for(int i = 2; i <= tot; i++) G[fail[i]].push_back(i);
	T = sqrt(n);
	for(int i = 1; i <= q; i++) {
		int l, r, k; scanf("%d%d%d", &l, &r, &k);
		if(len[k] > T) {
			L[k].push_back(make_pair(l , i)); 
			R[k].push_back(make_pair(r , i));
		}
		else {
			le[l].push_back(make_pair(k , i));
			ri[r].push_back(make_pair(k , i)); 
		}
	}
	for(int i = 1; i <= n; i++)
		if(len[i] > T) {
			int p = ed[i]; S[p] = 1;
			while(fa[p] != 1) S[p = fa[p]] = 1;
			dfs1(1);
			sort(L[i].begin(), L[i].end()), reverse(L[i].begin(), L[i].end());
			sort(R[i].begin(), R[i].end()), reverse(R[i].begin(), R[i].end());
			ll tmp = 0;
			for(int j = 1; j <= n; j++) {
				while(!L[i].empty() && L[i].back().first == j)
					ans[L[i].back().second] -= tmp, L[i].pop_back();
				tmp += S[ed[j]];
				while(!R[i].empty() && R[i].back().first == j)
					ans[R[i].back().second] += tmp, R[i].pop_back();
			}
			for(int j = 1; j <= tot; j++) S[j] = 0;
		}
	dfs2(1);
	for(int i = 1; i <= n; i++) {
		for(auto o : le[i]) {
			int p = ed[o.first];
			while(p != 1)
				ans[o.second] -= ask(dfn[p]), p = fa[p]; 
		}
		add(dfn[ed[i]], 1), add(dfn[ed[i]] + S[ed[i]] , -1);
		for(auto o : ri[i]) {
			int p = ed[o.first];
			while(p != 1)
				ans[o.second] += ask(dfn[p]), p = fa[p]; 
		}
	}
	for(int i = 1; i <= q; i++)
		printf("%lld\n", ans[i]);
	return 0;
}