#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int>v[100010];
int n, m, c[100010];
int main() {
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) scanf("%d", c+i);
    for (int i=0; i<m; i++) {
	int s, t;
	scanf("%d%d", &s, &t);
	s--; t--;
	if (c[s]!=c[t]) {
	    v[c[s]].push_back(c[t]);
	    v[c[t]].push_back(c[s]);
	}
    }

    for (int i=0; i<100010; i++) {
	sort(v[i].begin(), v[i].end());
	v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
    }
    sort(c, c+n);
    int ans=c[0];
    for (int i=0; i<n; i++) {
	if (v[ans].size()<v[c[i]].size()) ans=c[i];
    }
    printf("%d\n", ans);
    return 0;
}