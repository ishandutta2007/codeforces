#include <stdio.h>
#include <algorithm>
#define MN 1000000
int n,ans[MN+5],Gcd=1;
bool e[MN+5];
int gcd(int a,int b){
	if(a<b) std::swap(a,b);
	if(a%b==0) return b;
	return gcd(b,a%b);
}
void del(int x){
	if(e[x]) return;
	static int i=0;
	if(i<n-2){
		e[x]=true;
		ans[++i]=Gcd;
	}else{
		static int tmp=0;
		if(tmp==0){
			tmp=x;
			e[x]=true;
		}else{
			ans[++i]=gcd(tmp,x);
			ans[++i]=std::max(tmp,x);
		}
	}
}
int main(){
	scanf("%d",&n);
	if(n==1) return 0*puts("1");
	for(int l=2;;l<<=1){
		for(int i=l>>1;i<=n;i+=l) del(i);
		Gcd=l;
		if(l>n) break;
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}