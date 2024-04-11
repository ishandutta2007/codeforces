#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
template<class T>
struct Fenwick {
    int n;
    vector<T>data;
    Fenwick(int n) : n(n) {
	data=vector<T>(n);
    }
    void add(int p, T v) {
        for (; p<n; p|=p+1) data[p]+=v;
    }
    T sum(int l, int r) {
        if (l==0) {
            T t=0;
            for (; r; r&=r-1) t+=data[r-1];
            return t;
        } else {
            return sum(0, r)-sum(0, l);
        }
    }
};

LL tri(LL x) { return x*(x+1)/2; }
LL sum[17];

int N, M, A[100010];

	
int main() {
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; i++) scanf("%d", A+i);

    vector<Fenwick<int> > F(17, Fenwick<int>(N));
    for (int i=0; i<17; i++) {
	LL cnt = 0;
	for (int j=0; j<=N; j++) {
	    if (j<N && A[j] & (1<<i)) {
		F[i].add(j, 1);
		cnt++;
	    } else {
		if (cnt) {
		    sum[i] += tri(cnt);
		    cnt = 0;
		}
	    }
	}
    }

    for (;M--;) {
	int P, V;
	scanf("%d%d", &P, &V);
	P--;
	LL ans = 0;
	for (int i=0; i<17; i++) {
	    int left, right;
	    int l = -1, r = P;
	    for (;r-l>1;) {
		int m = (l+r)/2;
		if (F[i].sum(m, P) == P-m) r=m;
		else l=m;
	    }
	    left = r;
	    
	    l=P+1; r=N+1;
	    for (;r-l>1;) {
		int m = (l+r)/2;
		if (F[i].sum(P+1, m) == m-P-1) l=m;
		else r=m;
	    }
	    right = l;
	    
	    if ((V & (1<<i)) && F[i].sum(P, P+1)==0) {
		sum[i] = sum[i] - tri(P-left) - tri(right-P-1) + tri(right-left);
		F[i].add(P, 1);
	    } else  if ((~V & (1<<i)) && F[i].sum(P, P+1)==1) {
		sum[i] = sum[i] + tri(P-left) + tri(right-P-1) - tri(right-left);
		F[i].add(P, -1);
	    }
// 	    if (i<2) {
// 		for (int j=0; j<N; j++) printf("%d", F[i].sum(j, j+1));
// 		puts("");
// 	    }
	    ans += sum[i]<<i;
	}

	cout << ans << endl;
    }
    

    return 0;
}