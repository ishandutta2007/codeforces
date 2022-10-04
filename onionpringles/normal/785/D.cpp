#include <stdio.h>
#include <string.h>
#define mul(x,y) ((long long)(x)*(y)%mod)
const int N = 202020;
char b[N];
int a[N],c[N];
const int mod = 1000000007;
int iv[N],i;
int main(){
	scanf("%s",b+1);
	int n=strlen(b+1);
	for(i=1;i<=n;i++){
		if(b[i]=='(')a[i]++;
		a[i]+=a[i-1];
	}
	for(int i=n;i;i--){
		if(b[i]==')')c[i-1]++;
		c[i-1]+=c[i];
	}
	iv[1]=1;
	for(int i=2;i<N;i++)iv[i]=mul(mod-mod/i,iv[mod%i]);
	int x=c[0],y=c[0]-1;
	int res=c[0];
	int ans =0;
	for(int i=1;i<=n;i++){
		if(b[i]==')'){
			res=mul(res,iv[x]);
			res=mul(res,y);
			x--;y--;
		}
		if(b[i]=='(') ans = (ans+res)%mod;
		if(b[i]=='('){
			res = mul(res,x+1);
			res = mul(res,iv[x+1-y]);
			x++;
		}
	}
	printf("%d\n",ans);
}