#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, X1[16], Y1[16], X2[16], Y2[16];
int t, b, l, r;

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
	scanf("%d%d%d%d", X1+i, Y1+i, X2+i, Y2+i);
	X1[i] *= 2;
	Y1[i] *= 2;
	X2[i] *= 2;
	Y2[i] *= 2;
    }

    l=X1[0];
    r=X2[0];
    b=Y1[0];
    t=Y2[0];
    for (int i=0; i<N; i++) {
	l = min(l, X1[i]);
	r = max(r, X2[i]);
	b = min(b, Y1[i]);
	t = max(t, Y2[i]);
    }
    //printf("%d %d %d %d\n", l, b, r, t);

    if (r-l != t-b) { puts("NO"); return 0; }

    for (int i=b; i<=t; i++) {
	vector<pair<int,int> > v;
	for (int j=0; j<N; j++) {
	    if (Y1[j]<=i && i<=Y2[j])
		v.push_back(make_pair(X1[j], X2[j]));
	}
	if (v.empty()) { puts("NO"); return 0; }
	sort(v.begin(), v.end());
	if (v[0].first != l) { puts("NO"); return 0; }
	int p=v[0].second;

	for (int j=0; j<int(v.size()); j++) {
	    if (v[j].first > p) { puts("NO"); return 0; }
	    p = max(p, v[j].second);
	}
	if (p!=r) { puts("NO"); return 0; }
    }
    puts("YES");
    return 0;
}