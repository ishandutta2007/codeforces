#include<bits/stdc++.h>
using namespace std;
int n,m;
int seq[30];

int print(int x){
	printf("%d\n",x);
	fflush(stdout);
	int d;
	scanf("%d",&d);
	return d;
}

int main(){
	scanf("%d%d",&m,&n);
	int d=print(1);
	if(!d) exit(0);
	seq[0]=d;
	for(int i=1;i<n;++i) seq[i]=print(1);
	int l=2, r=m,mid;
	int cnt=0;
	while(l<=r){
		mid=l+r>>1;
		int d=print(mid);
		if(!d) exit(0);
		if(d==seq[cnt]) l=mid+1;
		else r=mid-1;
		cnt=(cnt+1)%n;
	}
	return 0;
}