#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
ll A[35],B[35];
int main(){
	for(int i=1;i<32;++i)A[i]=(A[i-1]<<2)+1,B[i]=B[i-1]+(1ll<<i)-1;
	int T=gi();
	while(T--){
		ll n=gi(),k=gi();
		if(n>31){printf("YES %d\n",n-1);goto GG;}
		if(k>A[n]){puts("NO");goto GG;}
		for(int i=n-1;~i;--i)
			if(B[n-i]<=k&&A[n]-A[i]*((1ll<<(n-i+1))-1)>=k)
			{printf("YES %d\n",i);goto GG;}
		puts("NO");GG:;
	}
	return 0;
}