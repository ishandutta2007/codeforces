#include<cstdio>

int N, T, A[100010];
int main() {
    scanf("%d%d", &N, &T);
    for (int i=0; i<N; i++) scanf("%d", A+i);
    int s=0, ans=0, cnt=0, l=0, r=0;
    for (;l<N;) {
	if (s<T) {
	    if (r==N) break;
	    s+=A[r++];
	    cnt++;
	} else {
	    s-=A[l++];
	    cnt--;
	}
	if (s<=T && ans<cnt) ans=cnt;
    }
    
    printf("%d\n", ans);
    
    return 0;
}