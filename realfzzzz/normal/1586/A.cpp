#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
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
	int T=readint();
	while(T--){
		int n=readint(),p=0,s=0;
		for(int i=1;i<=n;i++){
			int a=readint();
			if(a%2==1) p=i;
			s+=a;
		}
		bool flag=1;
		for(int i=2;i*i<=s;i++) flag&=s%i!=0;
		if(flag){
			printf("%d\n",n-1);
			for(int i=1;i<=n;i++) if(i!=p) printf("%d ",i);
			printf("\n");
		}
		else{
			printf("%d\n",n);
			for(int i=1;i<=n;i++)  printf("%d ",i);
			printf("\n");
		}
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}