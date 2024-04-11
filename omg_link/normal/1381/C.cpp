#include <stdio.h>
#include <algorithm>
#define MN 100000

int n,x,y,wColor,c[MN+5],ans[MN+5];
int cnt[MN+5],rk[MN+5];
int totWaste,cntWaste[MN+5],cntSelf[MN+5];
int pool[MN+5],st[MN+5];

void setWaste(int tot){
	totWaste += tot; 
	while(tot>0){
		int p = 1;
		while(cnt[rk[p+1]]==cnt[rk[p]]) p++;
		while(tot>0&&p>0){
			cntWaste[rk[p]]++;
			cnt[rk[p]]--;
			p--,tot--;
		}
	}
}

void setSelf(int tot){
	while(tot>0){
		int p = 1;
		while(cnt[rk[p+1]]==cnt[rk[p]]) p++;
		while(tot>0&&p>0){
			cntSelf[rk[p]]++;
			cnt[rk[p]]--;
			p--,tot--;
		}
	}
}

void solve(){
	scanf("%d%d%d",&n,&x,&y);
	totWaste = 0;
	for(int i=1;i<=n+1;i++){
		rk[i] = i;
		cntWaste[i] = 0;
		cntSelf[i] = 0;
		cnt[i] = 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		cnt[c[i]]++;
	}
	for(int i=1;i<=n+1;i++)
		if(cnt[i]==0){
			wColor = i;
			break;
		}
	std::sort(rk+1,rk+1+n+1,[](int a,int b)->bool{
		return cnt[a]>cnt[b];
	});
	int wNum = (n-y)+x;
	if(wNum>n){
		puts("NO");
		return;
	}
	setSelf(x);
	setWaste(n-y);
	for(int i=1;i<=n+1;i++)
		cnt[i] += cntWaste[i];
	if(cnt[rk[1]]+cnt[rk[1]]-cntWaste[rk[1]]>n-wNum+totWaste){
		puts("NO");
		return;
	}
	int cycleDelta = cnt[rk[1]]-cntWaste[rk[1]];
	int cntPool = 0;
	for(int i=1;i<=n+1;i++){
		int t = rk[i];
		st[t] = st[rk[i-1]]+cnt[rk[i-1]];
		for(int j=0;j<cnt[t]-cntWaste[t];j++){
			pool[cntPool+j] = t;
		}
		cntPool += cnt[t]-cntWaste[t];
	}
	for(int j=0;j<totWaste;j++){
		pool[cntPool+j] = wColor;
	}
	cntPool += totWaste;
	puts("YES");
	for(int i=1;i<=n;i++){
		if(cntSelf[c[i]]>0){
			printf("%d ",c[i]);
			cntSelf[c[i]]--;
			continue;
		}
		cnt[c[i]]--;
		printf("%d ",pool[(st[c[i]]+cnt[c[i]]+cycleDelta)%cntPool]);
	}
	puts("");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}