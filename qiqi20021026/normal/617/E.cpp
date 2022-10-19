#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

#define LL long long

int n,m,p,f[100030],a[100030],cnt[2000030];
LL ans,ANS[100030];
struct quiz{
	int l,r,b,i;
	
	bool operator < (const quiz &n) const {
		return (b<n.b) || (b==n.b && r<n.r);
	}
}q[100030];

int main(){
	scanf("%d%d%d",&n,&m,&p);
	int BASE=sqrt(n)+1;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[i]=f[i-1]^a[i];
	}
	for (int i=1;i<=m;i++){
		q[i].i=i;
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].b=(q[i].l-1)/BASE+1;
	}
	
	sort(q+1,q+m+1);
	
	int l=0,r=0; cnt[0]=1;
	for (int i=1;i<=m;i++){
		while (r<q[i].r) r++,ans+=cnt[f[r]^p],cnt[f[r]]++;
		while (l>q[i].l-1) l--,ans+=cnt[f[l]^p],cnt[f[l]]++;
		while (l<q[i].l-1) cnt[f[l]]--,ans-=cnt[f[l]^p],l++;
		while (r>q[i].r) cnt[f[r]]--,ans-=cnt[f[r]^p],r--;
		ANS[q[i].i]=ans;
	}
	
	for (int i=1;i<=m;i++) printf("%I64d\n",ANS[i]);
	
	return 0;
}