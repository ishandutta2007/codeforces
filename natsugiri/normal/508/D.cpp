#include<set>
#include<map>
#include<stack>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }

// Directed Graph
typedef vector<vector<int> > Adj;
vector<int> eularianPath(Adj G) { // [x->y->...->z]
    int N = G.size(), cnt = 0, x = 0, diff = 0;
    vector<int> in(N), ret;
    for (int v=0; v<N; v++) {
	cnt += G[v].size();
	for (int i=0; i<(int)G[v].size(); i++) in[G[v][i]]++;
    }
    for (int i=0; i<N; i++) {
	diff += abs(in[i] - (int)G[i].size());
	if (diff > 2) return vector<int>(); // unbalanced degree vertices
	if (in[i] < (int)G[i].size()) x = i; // choosing start
    }
    stack<int> S;
    S.push(x);
    while (!S.empty()) {
	int v = S.top();
	if (G[v].size()) {
	    S.push(G[v].back());
	    G[v].pop_back();
	} else {
	    S.pop();
	    ret.push_back(v);
	}
    }
    if ((int)ret.size() != cnt+1) return vector<int>(); // not connected
    reverse(ret.begin(), ret.end());
    return ret;
}

Adj G;
map<string, int> mp;
vector<string> rmp;
int word2ver(char a, char b) {
    string s; s+=a; s+=b;
    if (mp.count(s) == 0) {
	mp[s] = rmp.size();
	rmp.push_back(s);
	G.push_back(vector<int>());
    }
    return mp[s];
}
string ver2word(int n) {
    return rmp[n];
}

int N;
char buf[99];
int main() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%s", buf);
	int p = word2ver(buf[0], buf[1]);
	int q = word2ver(buf[1], buf[2]);
	G[p].push_back(q);
    }

    vector<int> es = eularianPath(G);

    if (es.size()) {
	puts("YES");
	// EACH (e, es) cerr << e->src << "\n";
	EACH (e, es) putchar(ver2word(*e)[0]);
	putchar(ver2word(es.back())[1]);
	putchar('\n');
    } else {
	puts("NO");
    }
    
    return 0;
}