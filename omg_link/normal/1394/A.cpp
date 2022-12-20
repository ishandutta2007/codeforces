#include <stdio.h>
#include <algorithm>
#define MN 100000
typedef long long LL;
int n,d,m,a[MN+5];
LL tempAns=0,realAns=0;
int unused=0,tail;

void take(){
	if(unused>0){
		unused--;
	}else{
		if(tail>0){
			if(a[tail]<=m)
				tempAns -= a[tail];
			else
				tail=0;
			tail--;
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&d,&m);
	tail=n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	std::sort(a+1,a+1+n,std::greater<int>());
	for(int i=1;i<=n;i++){
		if(a[i]<=m) tempAns += a[i];
		else unused++;
	}
	realAns = tempAns;
	for(int i=1;i<=n;i++){
		if(a[i]<=m) break;
		tempAns += a[i];
		take();
		if(i!=1){
			for(int j=1;j<=d;j++) take();
		}
		if(tail<i) break;
		realAns = std::max(realAns,tempAns);
	}
	printf("%lld\n",realAns);
}