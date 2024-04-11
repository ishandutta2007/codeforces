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

int N, M, A[1000010];


int main() {
    scanf("%d%d", &N, &M);
    for (int i=0; i<M; i++) scanf("%d", A+i);

    //for (int i=0; i<M; i++) A[i]--;

    Fenwick<int> f(N);

    vector<short>v;

    for (int i=0; i<N; i++) {
	int t;
	scanf("%d", &t);

	if (t==-1) {
	    int p = upper_bound(A, A+M, f.sum(0, N)) - A;
	    for (;p--;) {
		int l=0, r=N;
		for (;r-l>1;) {
		    int m=(r+l)/2;
		    if (f.sum(0, m) >= A[p]) r=m;
		    else l=m;
		}
		f.add(r-1, -1);
	    }
	} else {
	    f.add(v.size(), 1);
	    v.push_back(t);
	}
    }
		
    vector<char>ans;
    for (int i=0; i<(int)v.size(); i++) {
	if (f.sum(i, i+1)) ans.push_back('0'+v[i]);
    }

    if (ans.size()) {
	for (int i=0; i<(int)ans.size(); i++) putchar(ans[i]);
	puts("");
    } else {
	puts("Poor stack!");
    }
    
    return 0;
}