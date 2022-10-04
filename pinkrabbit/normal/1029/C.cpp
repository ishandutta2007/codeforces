#include<cstdio>
#include<algorithm>
using namespace std;
int n,l[300005],r[300005],Ans;
int l1[300005],r1[300005];
int main(){
	scanf("%d",&n);
	r1[0]=2e9;
	for(int i=1;i<=n;++i) scanf("%d%d",l+i,r+i), l1[i]=max(l1[i-1],l[i]), r1[i]=min(r1[i-1],r[i]);
	int L=0, R=2e9;
	for(int i=n;i;--i) Ans=max(Ans,min(r1[i-1],R)-max(l1[i-1],L)), L=max(L,l[i]), R=min(R,r[i]);
	printf("%d",Ans);
	return 0;
}