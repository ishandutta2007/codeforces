#include <stdio.h>
#include <algorithm>
#define MN 100

int n,a[MN+5];

void firstWin(){
	puts("T");
}

void secondWin(){
	puts("HL");
}

void solve(){
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	std::sort(a+1,a+1+n,std::greater<int>());
	if(a[1]>sum-a[1]) firstWin();
	else{
		if(sum&1) firstWin();
		else secondWin();
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}