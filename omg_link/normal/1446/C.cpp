#include <stdio.h>
#include <algorithm>
#define MN 200000

int n,a[MN+5];

int hb(int x){
	int r = 0;
	while(x){
		x >>= 1;
		++r;
	}
	return r;
}

int solve(int L,int R){
	if(L==R) return 1;
	int mx=0,sz=-1;
	for(int i=L,id=1;i<=R;i++,id++){
		int l=i,r=i,s=hb(a[l]);
		while(r<R&&hb(a[r+1])==s) r++;
		for(int j=l;j<=r;j++)
			a[j] ^= (0x40000000>>(31-s));
		int t = solve(l,r);
		for(int j=l;j<=r;j++)
			a[j] ^= (0x40000000>>(31-s));
		sz++;
		mx = std::max(mx,t-std::max(id-2,0));
		i = r;
	}
	return mx + sz;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	std::sort(a+1,a+1+n);
	printf("%d\n",n-solve(1,n));
}