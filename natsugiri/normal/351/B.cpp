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


int main() {
    int N;
    scanf("%d", &N);

    Fenwick<int> f(N);
    int K=0;
    for (int i=0; i<N; i++) {
	int x; scanf("%d", &x);
	K += f.sum(x, N);
	f.add(x-1, 1);
    }

    //printf("%d\n", K);
    printf("%.6f\n", (double)(K/2*4 + K%2));
    
    return 0;
}