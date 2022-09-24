#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int n, m, k;
int a[100010], l[100010], r[100010], d[100010];
LL q[100010];
LL e[100010];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i=0; i<n; i++) scanf("%d", a+i);
    for (int i=0; i<m; i++) {
	scanf("%d%d%d", l+i, r+i, d+i);
	l[i]--;
    }
    
    for (int i=0; i<k; i++) {
	int x, y;
	scanf("%d%d", &x, &y);
	q[x-1]++; q[y]--;
    }

    for (int i=0; i<m; i++) q[i+1]+=q[i];

    for (int i=0; i<m; i++) {
	e[l[i]]+=q[i]*d[i];
	e[r[i]]-=q[i]*d[i];
    }
    for (int i=0; i<n; i++) e[i+1]+=e[i];
    for (int i=0; i<n; i++) cout<<a[i]+e[i]<<(i+1==n?'\n':' ');
    
	
    return 0;
}