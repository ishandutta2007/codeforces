#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;

int M;
LL A[2000010];

int main() {
    scanf("%d", &M);
    for (int i=0; i<M; i++) cin>>A[i];
    sort(A, A+M);
    for (int i=M; --i;) A[i-1] += A[i];

    LL ans=0;
    for (int i=1; i<=M; i*=4) {
	ans += A[M-i];
    }
    cout<<ans<<endl;
    return 0;
}