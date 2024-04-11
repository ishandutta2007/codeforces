#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;


int n, k, t;
set<vector<int> >se;
vector<int>v, w, q, s, r;

int main() {
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++) scanf("%d", &t), q.push_back(t-1);
    for (int i=0; i<n; i++) scanf("%d", &t), s.push_back(t-1);
    r=vector<int>(n);
    for (int i=0; i<n; i++) r[q[i]]=i;
    w=vector<int>(n);
    for (int i=0; i<n; i++) {
	if (k%2) w[i]=q[i];
	else w[i]=i;
    }
    for (int i=0; i<=k; i+=2) {
	se.insert(v=w);
	for (int j=0; j<n; j++) w[j]=v[q[q[j]]];
    }
    for (int i=0; i<n; i++) {
	if (k%2) w[q[i]]=i;
	else w[i]=i;
    }
    for (int i=0; i<=k; i+=2) {
	se.insert(v=w);
	for (int j=0; j<n; j++) w[q[q[j]]]=v[j];
    }
    for (int i=0; i<n; i++) v[i]=i;
    if (se.find(s)!=se.end() && s!=v && (k==1 || s!=q || s!=r)) puts("YES");
    else puts("NO");

    return 0;
}