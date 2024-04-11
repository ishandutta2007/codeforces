#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

const LL MOD=95542721;

int N, A[100010];

LL data[48][300010];
int le[300010], ri[300010];
int n, m;
void SegmentTree() {
    n=N;
    for (m=1; m<n;) m*=2;

    for (int i=0; i<n; i++) data[0][m+i]=A[i];
    for (int t=0; t<47; t++) {
	for (int i=0; i<n; i++) {
	    data[t+1][m+i] = data[t][m+i]*data[t][m+i]%MOD*data[t][m+i]%MOD;
	}
    }
    for (int t=0; t<48; t++) {
	for (int i=m; --i; ) {
	    data[t][i]=data[t][i*2]+data[t][i*2+1];
	    //data[t][i]%=MOD;
	}
    }
}
LL sum(const int&x, const int&y, int f, int k, int l, int r) {
    if (f>=48) f-=48;
    if (r<=x || y<=l) return 0;
    if (x<=l && r<=y) return data[f][k];
    return (sum(x, y, le[k]+f, k*2, l, (l+r)/2)
	    + sum(x, y, ri[k]+f, k*2+1, (l+r)/2, r));
}
LL sum(int x, int y) { return sum(x, y, 0, 1, 0, m); }

void cube(const int&x, const int&y, int k, int l, int r) {
    if (r<=x || y<=l) return;
    int mid=(l+r)/2;
    if (x<=l && mid<=y) {
	le[k]++;
	if (le[k]>=48) le[k]-=48;
    } else {
	cube(x, y, k*2, l, mid);
    }
    if (x<=mid && r<=y) {
	ri[k]++;
	if (ri[k]>=48) ri[k]-=48;
    } else {
	cube(x, y, k*2+1, mid, r);
    }
    for (int t=0; t<48; t++) {
	data[t][k] = (data[(le[k]+t)%48][k*2] + data[(ri[k]+t)%48][k*2+1]);
    }
}
void cube(int x, int y) { cube(x, y, 1, 0, m); }


int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
	scanf("%d", A+i);
	A[i]%=MOD;
    }
    
    SegmentTree();
    int Q; scanf("%d", &Q);
    for (;Q--;) {
	int t, x, y; scanf("%d%d%d", &t, &x, &y); x--;
	if (t==1) {
	    printf("%d\n", int(sum(x, y)%MOD));
	} else{ 
	    cube(x, y);
	}
    }	
    return 0;
}