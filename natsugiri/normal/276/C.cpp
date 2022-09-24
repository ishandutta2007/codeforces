#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


typedef long long LL;

int N, Q, A[200010], S[200010];
int main() {
    scanf("%d%d", &N, &Q);
    for (int i=0; i<N; i++) scanf("%d", A+i);

    for (;Q--;) {
	int L, R;
	scanf("%d%d", &L, &R);
	S[L-1]++; S[R]--;
    }

    for (int i=0; i<N; i++) S[i+1]+=S[i];
    sort(A, A+N); sort(S, S+N);

    LL ans=0;
    for (int i=0; i<N; i++) ans+=LL(S[i])*A[i];
    cout<<ans<<endl;

    return 0;
}