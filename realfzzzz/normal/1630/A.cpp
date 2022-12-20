#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=read();
	while(T--){
		int n,k;
		n=read();
		k=read();
		if(k==n-1){
			if(n==4) printf("-1\n");
			else{
				printf("%d %d\n",(n>>1)-1,n-1);
				printf("%d %d\n",n>>1,n-2);
				printf("0 %d\n",(n-1)^(n-2));
				for(int i=1;i<n-2;i++)
					if(i!=(n>>1)-1&&i!=(n>>1)&&i!=((n-1)^(n-2))&&(i&1))
						printf("%d %d\n",i,(n-1)^i);
			}
			continue;
		}
		printf("%d %d\n",k,n-1);
		if(k) printf("0 %d\n",(n-1)^k);
		for(int i=1;i<n-1;i++)
			if(i!=k&&i!=((n-1)^k)&&(i&1))
				printf("%d %d\n",i,(n-1)^i);
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}