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
        //for (; p<n; p|=p+1) data[p]+=v;
	for (; p;p&=p-1) data[p-1]+=v;
    }
    T get(int p) {
	T r=0;
	for (; p<n; p|=p+1) r+=data[p];
	return r;
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
int main() {
    int N; scanf("%d", &N);
    double sum=0;
    int sz=1;
    Fenwick<double> f(N);
    
    for (;N--;) {
	int t; scanf("%d", &t);
	if (t==1) {
	    int a, x;
	    scanf("%d%d", &a, &x);
	    f.add(a, x);
	    sum+=a*x;
	}
	if (t==2) {
	    int k; scanf("%d", &k);
	    f.add(sz, -k);
	    sz++;
	    f.add(sz, k);
	    sum+=k;
	}
	if (t==3) {
	    double k=f.get(sz-1);
	    f.add(sz, -k);
	    sz--;
	    f.add(sz, k);
	    sum-=k;
	}
	printf("%.9f\n", sum/sz);
    }
    return 0;
}