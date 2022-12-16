#include <stdio.h>
#include <algorithm>
#define MN 200000

using std::sort;

int n,p[MN+5],q[MN+5],b[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
		scanf("%1d",&b[i]);
	for(int i=1;i<=n;i++)
		q[i] = i;
	sort(q+1,q+1+n,[](int x,int y)->bool{
		if(b[x]!=b[y])
			return b[x]<b[y];
		else
			return p[x]<p[y];
	});
	for(int i=1;i<=n;i++)
		p[q[i]] = i;
	for(int i=1;i<=n;i++)
		printf("%d%c",p[i]," \n"[i==n]);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}