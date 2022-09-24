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

int N, A[5010];
pair<int,int> Z[5010];

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", A+i);


    for (int i=0; i<N; i++) Z[i] = make_pair(A[i], i);
    sort(Z, Z+N);
    int tm = 0, cnt = 0; 


    for (int i=0; i<N; i++) {
	Fenwick<int> f(N);
	for (int j=i+1; j<N; j++) {
	    if (Z[j].second < Z[i].second) {
		int tmp = f.sum(Z[j].second, Z[i].second) * 2 + 1;
		if (tmp > tm) { tm = tmp; cnt=0; }
		if (tm==tmp) cnt++;
	    }
		    
	    f.add(Z[j].second, 1);
	}
    }

    int cst = 0;
    Fenwick<int>f(N);
    for (int i=0; i<N; i++) {
	cst += f.sum(Z[i].second, N);
	f.add(Z[i].second, 1);
    }

    printf("%d %d\n", cst - tm, cnt);
	    
    return 0;
}