#include <cstdio>
 
int cnt[200001];
const int zero=100000;
 
int main(void) {
	int c;
	scanf("%d\n",&c);
	for(int t=0;t<c;t++) {
		int n,x;
		scanf("%d %d\n",&n,&x);
		for(int i=zero-n;i<=zero+n;i++) {
			cnt[i]=0;
		}
		int ret=0;
		if (x==0) {
			ret++;
		}
		int pre=0;
		for(int i=0;i<n;i++) {
			int k;
			scanf("%1d",&k);
			if (k==0) {
				pre++;
			}
			else {
				pre--;
			}
			cnt[zero+pre]++;
		}
		scanf("\n");
		if (pre==0) {
			if (zero+x>=zero-n&&zero+x<=zero+n) {
			    if (cnt[zero+x]==0) {
			        printf("0\n");
			    }
			    else {
			        printf("-1\n");
			    }
			}
			else {
			    printf("0\n");
			}
			continue;
		}
		if (pre>0) {
			for(int i=zero-n;i<=zero+x&&i<=zero+n;i++) {
				if ((zero+x-i)%pre==0) {
					ret+=cnt[i];
				}
			}
		}
		else {
			for(int i=zero+n;i>=zero+x&&i>=zero-n;i--) {
				if ((i-zero-x)%(-pre)==0) {
					ret+=cnt[i];
				}
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}