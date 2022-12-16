#include <stdio.h>
#include <algorithm>
#define MN 200000

int n,m,pre[MN+5],suf[MN+5];
char s[MN+5],t[MN+5];

int main(){
	scanf("%d%d%s%s",&n,&m,&s[1],&t[1]);
	for(int i=1,j=1;i<=n;i++){
		if(s[i]==t[j]){
			pre[j] = i;
			j++;
		}
	}
	for(int i=n,j=m;i>=1;i--){
		if(s[i]==t[j]){
			suf[j] = i;
			j--;
		}
	}
	int ans = 0;
	for(int i=1;i<=m-1;i++){
		ans = std::max(ans,suf[i+1]-pre[i]);
	}
	printf("%d\n",ans);
}