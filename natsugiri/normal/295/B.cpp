#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const LL INF=1e15;

int n, a[555][555], r[555];
LL d[555][555], o[555];
LL b[555][555];


int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) scanf("%d", a[i]+j);
    for (int i=n; i--; ) {
	scanf("%d", r+i);
	r[i]--;
    }
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) b[i][j]=a[r[i]][r[j]];
    
    //for (int i=0; i<n; i++) for (int j=0; j<n; j++) d[i][j]=INF;

    for (int k=0; k<n; k++) {
	for (int i=0; i<n; i++) {
	    for (int j=0; j<n; j++) {
		b[i][j]=min(b[i][j], b[i][k]+b[k][j]);
		if (i<=k && j<=k) o[k]+=b[i][j];
	    }
	}
    }

    for (int i=n; i--; ) cout<<o[i]<<(i?' ':'\n');

    return 0;
}