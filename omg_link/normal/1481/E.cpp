#include <stdio.h>
#include <algorithm>
#define MN 500000
const int INF = 0x3fffffff;

int n,a[MN+5],cnt[MN+5],pre[MN+5],suf[MN+5];
struct seg{
	int l=INF,r=-INF,cnt=0;
}s[MN+5];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		s[a[i]].l = std::min(s[a[i]].l,i);
		s[a[i]].r = std::max(s[a[i]].r,i);
		s[a[i]].cnt++;
	}
	for(int i=n;i>=1;i--){
		suf[i] = std::max(suf[i+1],++cnt[a[i]]);
	}
	std::sort(s+1,s+1+n,[](seg a,seg b)->bool{
		return a.l < b.l;
	});
	for(int i=1,j=1;i<=n;i++){
		pre[i] = std::max(pre[i],pre[i-1]);
		if(s[j].l==i){
			pre[s[j].r] = pre[i-1]+s[j].cnt;
			j++;
		}
	}
	int ans = 0;
	for(int i=0;i<=n;i++){
		ans = std::max(ans,pre[i]+suf[i+1]);
	}
	printf("%d\n",n-ans);
}