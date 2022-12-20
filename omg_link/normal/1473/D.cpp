#include <stdio.h>
#include <algorithm>
#define MN 200000

int n,q;
char o[MN+5];
int preMin[MN+5],preMax[MN+5],preFin[MN+5];
int sufMin[MN+5],sufMax[MN+5];

void solve(){
	scanf("%d%d",&n,&q);
	scanf("%s",&o[1]);
	for(int i=1;i<=n;i++){
		if(o[i]=='+')
			preFin[i] = preFin[i-1]+1;
		else
			preFin[i] = preFin[i-1]-1;
		preMax[i] = std::max(preMax[i-1],preFin[i]);
		preMin[i] = std::min(preMin[i-1],preFin[i]);
	}
	sufMax[n+1] = sufMin[n+1] = 0;
	for(int i=n;i>=1;i--){
		if(o[i]=='+'){
			sufMax[i] = sufMax[i+1]+1;
			sufMin[i] = sufMin[i+1]+1;
		}else{
			sufMax[i] = sufMax[i+1]-1;
			sufMin[i] = sufMin[i+1]-1;
		}
		sufMax[i] = std::max(sufMax[i],0);
		sufMin[i] = std::min(sufMin[i],0);
	}
	for(int l,r;q--;){
		scanf("%d%d",&l,&r);
		int min = std::min(preMin[l-1],preFin[l-1]+sufMin[r+1]);
		int max = std::max(preMax[l-1],preFin[l-1]+sufMax[r+1]);
		printf("%d\n",max-min+1);
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}