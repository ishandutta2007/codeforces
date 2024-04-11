#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<vector<int> > Mat;

int N;
string s[100010], pattern;
Mat G;
int* fail;

int *buildFail(const string&p) {
    int m = p.size();
    int *fail = new int[m+1];
    int j = fail[0] = -1;
    for (int i = 1; i <= m; ++i) {
	while (j >= 0 && p[j] != p[i-1]) j = fail[j];
	fail[i] = ++j;
    }
    return fail;
}
pair<int,int> match(const string&t, const string&p, int *fail, int k) {
    int n = t.size(), m = p.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
	while (k >= 0 && p[k] != t[i]) k = fail[k];
	if (++k >= m) {
	    ++count; // match at t[i-m+1 .. i]
	    k = fail[k];
	}
    }
    return make_pair(count, k);
}

int rec(int v, int k) {
    pair<int,int>t=match(s[v], pattern, fail, k);
    int r=t.first;
    for (int i=0; i<int(G[v].size()); i++) {
	r+=rec(G[v][i], t.second);
    }
    return r;
}
int main() {
    scanf("%d", &N);
    G=Mat(N);
    for (int i=1; i<N; i++) {
	int x; scanf("%d", &x); x--;
	cin>>s[i];
	//G[i].push_back(x);
	G[x].push_back(i);
    }
    cin>>pattern;
    fail=buildFail(pattern);
    cout<<rec(0, 0)<<endl;
    return 0;
}