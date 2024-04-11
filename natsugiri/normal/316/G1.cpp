#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<set>
using namespace std;

typedef long long LL;

vector<int>buildFail(const string& p) {
    int m = p.size();
    vector<int>fail(m+1);
    int j = fail[0] = -1;
    for (int i = 1; i <= m; ++i) {
	while (j >= 0 && p[j] != p[i-1]) j = fail[j];
	fail[i] = ++j;
    }
    return fail;
}
int match(const string&t, const string&p, const vector<int>fail) {
    int n = t.size(), m = p.size();
    int count = 0;
    for (int i = 0, k = 0; i < n; ++i) {
	while (k >= 0 && p[k] != t[i]) k = fail[k];
	if (++k >= m) {
	    ++count; // match at t[i-m+1 .. i]
	    k = fail[k];
	}
    }
    return count;
}

int N, M;
string S;
string P[16]; int L[16], R[16];

int main() {
    cin>>S>>N;
    for (int i=0; i<N; i++) {
	cin>>P[i]>>L[i]>>R[i];

    }

    set<string>se;
    int ans=0;
    M=S.size();
    for (int i=0; i<M; i++) {
	for (int j=i+1; j<=M; j++) {
	    string X=S.substr(i, j-i);
	    if (!se.insert(X).second) continue;
	    vector<int>fail = buildFail(X);
	    bool ok=true;
	    for (int k=0; ok && k<N; k++) {
		int cnt=match(P[k], X, fail);
		if (cnt<L[k] || R[k]<cnt) ok=false;
	    }
	    if (ok) ans++;
	    //if (ok) cout<<X<<endl;
	}
    }
    cout<<ans<<endl;

    return 0;
}