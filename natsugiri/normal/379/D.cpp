#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int K, X, N, M;

char le[55], ri[55];
LL cnt[55];
bool solve(const string&S1, const string&S2) {
    le[1] = S1[0]; ri[1] = S1[N-1];
    cnt[1] = 0;
    for (int i=0; i<N-1; i++) if (S1[i]=='A' && S1[i+1]=='C') cnt[1]++;
	
    le[2] = S2[0]; ri[2] = S2[M-1];
    cnt[2] = 0;
    for (int i=0; i<M-1; i++) if (S2[i]=='A' && S2[i+1]=='C') cnt[2]++;

    for (int i=3; i<=K; i++) {
	le[i] = le[i-2];
	ri[i] = ri[i-1];
	cnt[i] = cnt[i-2] + cnt[i-1];
	if (ri[i-2]=='A' && le[i-1]=='C') cnt[i]++;

	if (cnt[i]>X) return false;
    }
    return cnt[K]==X;
}

int main() {
    scanf("%d%d%d%d", &K, &X, &N, &M);
    string A(N, 'A'), B(M, 'A');

    for (A[0]='A'; A[0]<'D'; A[0]++) {
	for (A[N-1]='A'; A[N-1]<'D'; A[N-1]++) {
	    for (int al=1; al<=N; al++) {
		for (int i=1; i<N-1; i++) {
		    if (i<al) A[i] = (A[i-1]=='A' ? 'C' : 'A');
		    else A[i] = 'B';
		}

		for (B[0]='A'; B[0]<'D'; B[0]++) {
		    for (B[M-1]='A'; B[M-1]<'D'; B[M-1]++) {
			for (int bl=1; bl<=M; bl++) {
			    for (int i=1; i<M-1; i++) {
				if (i<bl) B[i] = (B[i-1]=='A' ? 'C' : 'A');
				else B[i] = 'B';
			    }

			    if (solve(A, B)) {
				cout << A << endl;
				cout << B << endl;
				return 0;
			    }}}}}}}

    cout << "Happy new year!" << endl;
			
			
    
    return 0;
}