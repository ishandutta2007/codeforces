#include <stdio.h>
#define MN 300000

using ll = long long;

int n,q,mod;
int f[MN+5];
ll _a[MN+5],*a=&_a[1];

int cnt = 0;

void add(int p,int x){
	if(p>n) return;
	if(a[p]!=0) cnt--;
	a[p] = (a[p]+x)%mod;
	if(a[p]!=0) cnt++;
}

void rem(int p,int x){
	add(p,mod-x);
}

int main(){
	scanf("%d%d%d",&n,&q,&mod);
	f[1] = 1%mod;
	for(int i=2;i<=n;i++){
		f[i] = (f[i-1]+f[i-2])%mod;
	}
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a[i] += x;
	}
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a[i] -= x;
	}
	for(int i=n;i>=1;i--){
		a[i] = (a[i]-a[i-1]-a[i-2])%mod;
		if(a[i]<0){
			a[i] += mod;
		}
		if(a[i]!=0) cnt++;
	}
	while(q--){
		char c;
		int l,r;
		scanf(" %c%d%d",&c,&l,&r);
		if(c=='A'){
			add(l,1);
			rem(r+1,f[r-l+2]);
			rem(r+2,f[r-l+1]);
		}
		if(c=='B'){
			rem(l,1);
			add(r+1,f[r-l+2]);
			add(r+2,f[r-l+1]);
		}
		puts(cnt==0?"YES":"NO");
	}
}