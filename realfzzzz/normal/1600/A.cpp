#include<bits/stdc++.h>
#define rgi register int
#define FOR(i,a,b) for(rgi i=a;i<=b;++i)
using namespace std;
const int N=400010;
int n,a[N],ans[N];
char s[N];
signed main(){
	scanf("%d",&n);
	FOR(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1),scanf("%s",s+1);
	for(rgi l=1,r=n;l<=r;){
		rgi w=r-l+1;
		if(s[w]==s[w-1])ans[w]=l++;
		else ans[w]=r--;
	}
	FOR(i,1,n)printf("%d %c\n",a[ans[i]],"LR"[(ans[i]&1)^(n&1)^(s[n]=='R')]);
	return 0;
}