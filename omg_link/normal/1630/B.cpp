#include <stdio.h>
#define MN 200000

int n,k,a[MN+5],cnt[MN+5];

bool isEnough(int x){
	return x>=n-x+k;
}


void printAnswer(int x,int y){
	printf("%d %d\n",x,y);
	int l = 1;
	for(int i=1;i<k;i++){
		int r = l-1;
		int cnt[2] = {0};
		while(cnt[0]>=cnt[1]){
			++r;
			cnt[x<=a[r]&&a[r]<=y]++;
		}
		printf("%d %d\n",l,r);
		l = r+1;
	}
	printf("%d %d\n",l,n);
}

void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		cnt[i] = 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		cnt[i] += cnt[i-1];
	}
	int ansl = 1;
	int ansr = n;
	for(int l=1,r=1;l<=n;l++){
		while(r<=n&&!isEnough(cnt[r]-cnt[l-1])) r++;
		if(r>n) break;
		if(r-l<ansr-ansl){
			ansl = l;
			ansr = r;
		}
	}
	printAnswer(ansl,ansr);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}