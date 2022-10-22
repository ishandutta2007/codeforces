#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int a[100005],n,maxi[100005],mini[100005],x[100005],cnt[100005]; 
signed main(){
	int q,w;
	scanf("%d%d%d",&n,&w,&q);
	FOR(i,1,n)scanf("%d",&a[i]);
	FOR(i,1,q)scanf("%d",&x[i]),x[i]=w-x[i],maxi[i]=mini[i]=a[1];
	FOR(i,2,n)FOR(j,1,q){
		if(mini[j]>a[i])mini[j]=a[i];
		if(maxi[j]<a[i])maxi[j]=a[i];
		if(maxi[j]-x[j]>mini[j]){
			maxi[j]=mini[j]=a[i];
			cnt[j]++;
		}
	}
	FOR(i,1,q)printf("%d\n",cnt[i]);
	return 0;
}