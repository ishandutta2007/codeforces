#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
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

int N, A[1000011];
int L[1000011], R[1000011];

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", A+i);
    
    {
	map<int,int>mp;
	for (int i=0; i<N; i++)
	    L[i] = ++mp[A[i]];
    }
    { 
	map<int,int>mp;
	for (int i=N; i--;)
	    R[i] = ++mp[A[i]];
    }

    Fenwick<LL> S(N+10);
    for (int i=0; i<N; i++) S.add(R[i], 1);

    LL ans = 0;
    for (int i=0; i<N; i++) {
	S.add(R[i], -1);
	ans += S.sum(0, L[i]);
    }

    cout << ans << endl;
    return 0;
}