#include<bits/stdc++.h>

using namespace std;

#define N 320000
#define LL long long

LL n,ans,a[N],nxt[N],lst[300],fst[300],mx[300];
char c[N];

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		c[i]=getchar(); while (c[i]!='G' && c[i]!='B' && c[i]!='R') c[i]=getchar(); 
		nxt[lst[c[i]]]=i;
		lst[c[i]]=i;
		if (fst[c[i]]==0) fst[c[i]]=i;
	}
	if (!fst['G']){
		printf("%d\n",a[lst['B']]-a[fst['B']]+a[lst['R']]-a[fst['R']]);
		return 0;
	}
	if (fst['B'] && fst['G']>fst['B']) ans+=a[fst['G']]-a[fst['B']];
	if (fst['R'] && fst['G']>fst['R']) ans+=a[fst['G']]-a[fst['R']];
	if (lst['G']<lst['B']) ans+=a[lst['B']]-a[lst['G']];
	if (lst['G']<lst['R']) ans+=a[lst['R']]-a[lst['G']];
	for (LL i=fst['G'];nxt[i]!=0;i=nxt[i]){
		lst['R']=lst['B']=a[i];
		mx['R']=mx['B']=0;
		for (LL j=i+1;j<=nxt[i]-1;j++){
			if (a[j]-lst[c[j]]>mx[c[j]]) mx[c[j]]=a[j]-lst[c[j]];
			lst[c[j]]=a[j];
		}
		mx['R']=max(mx['R'],a[nxt[i]]-lst['R']);
		mx['B']=max(mx['B'],a[nxt[i]]-lst['B']);
		ans+=min((a[nxt[i]]-a[i])*3-mx['R']-mx['B'],(a[nxt[i]]-a[i])*2);
	}
	printf("%lld\n",ans);
	
	return 0;
}