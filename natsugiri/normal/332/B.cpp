#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const LL INF = 1LL<<60;
int N, K;
vector<int>L, R;
vector<LL>X, S;



int main() {
    scanf("%d%d", &N, &K);
    for (int i=0; i<N; i++) {
	int x; scanf("%d", &x);
	X.push_back(x);
    }
    S.push_back(0);
    for (int i=0; i<K; i++) S[0] += X[i];
    for (int i=K; i<N; i++) {
	LL tmp = S.back() + X[i] - X[i-K];
	S.push_back(tmp);
    }

    int M = S.size();
    L = R = vector<int>(M);
    L[0] = 0; R[M-1] = M-1;
    for (int i=1; i<M; i++) {
	L[i] =  (S[i] > S[L[i-1]] ? i : L[i-1]);
	R[M-i-1] = (S[M-i-1] >= S[R[M-i]] ? M-i-1 : R[M-i]);
    }

    int a=0, b=K;
    LL ma = S[0] + S[K];

    for (int i=0; i<M-K; i++) {
	LL tmp = S[L[i]] + S[R[i+K]];

	if (ma < tmp ||
	    (ma == tmp &&
	     (a > L[i] || (a == L[i] && b > R[i+K])))) {
	    ma = tmp;
	    a = L[i];
	    b = R[i+K];
	}
    }
	
    printf("%d %d\n", a+1, b+1);


    return 0;
}