#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

typedef long long ll;
ll root,n,k,ans,tot=1;
int ch[20000005][2],siz[20000005],a[20000005];

void insert(int x){
	int now=root;
	siz[root]++;
	for(int i=30;i>=0;i--){
		if(!ch[now][(x>>i)&1])
			ch[now][(x>>i)&1]=++tot;
		now=ch[now][(x>>i)&1];
		siz[now]++;
	}
}

int find(int now){
	int ret=0,p=root;
	for(int i=30;i>=0;i--){
		if(!((k>>i)&1))
			ret+=siz[ch[p][((now>>i)&1)^1]];
		p=ch[p][((now^k)>>i)&1];
	}
	return ret+siz[p];
}

int main(){
	root=1;
	scanf("%d%d",&n,&k);
	int now=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		now^=a[i];
		insert(now);
		ans+=find(now);
		if(now>=k)
			ans++;
	}
	printf("%lld",ans);
	return 0;
}