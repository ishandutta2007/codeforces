#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

string s;
int n, k;
vector<int>sa, rank, lcp;
bool cmp(const int a, const int b) {
    return rank[a]!=rank[b] ? rank[a]<rank[b] : 
	(a+k<=n ? rank[a+k] : -1) < (b+k<=n ? rank[b+k] : -1);
}
void SuffixArray() {
    n = s.size();
    sa.resize(n+1);
    rank.resize(n+1);
    vector<int>tmp(n+1);
    for (int i=0; i<=n; i++) {
	sa[i]=i;
	rank[i]=s[i];
    }
    for (k=1; k<=n; k*=2) {
	sort(sa.begin(), sa.end(), cmp);
	tmp[sa[0]]=0;
	for (int i=1; i<=n; i++) {
	    tmp[sa[i]]=tmp[sa[i-1]] + (cmp(sa[i-1], sa[i])?1:0);
	}
	for (int i=0; i<=n; i++) rank[i]=tmp[i];
    }
    
    lcp=vector<int>(n);
    for (int i=0; i<=n; i++) rank[sa[i]]=i;
    int h=0;
    lcp[0] = 0;
    for (int i=0; i<n; i++) {
	int j=sa[rank[i]-1];
	if (h>0) h--;
	for (; j+h<n && i+h<n; h++)
	    if (s[j+h]!=s[i+h]) break;
	lcp[rank[i]-1]=h;
    }
}

int main() {
    string S, T;
    cin >> S >> T;
    s = S + "$" + T + "~";
    SuffixArray();

    bool ok = false;
    int ans = s.size();
    for (int i=2; i<(int)s.size(); i++) {
	//cerr << s.substr(sa[i]) << endl;
	
	if (min(sa[i], sa[i+1]) < (int)S.size() && max(sa[i], sa[i+1]) > (int)S.size()) {
	    if (lcp[i] > lcp[i-1] && lcp[i] > lcp[i+1]) {
		ok = true;
		ans = min(ans, max(lcp[i-1], lcp[i+1])+1);
	    }
	}
    }

    if (!ok) puts("-1");
    else printf("%d\n", ans);
    return 0;
}