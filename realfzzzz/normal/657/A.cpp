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
	int n,d,h;
	n=readint();
	d=readint();
	h=readint();
	if(h*2<d||(h==1&&d==1&&n>2)){
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=h;i++) printf("%d %d\n",i,i+1);
	if(h<d){
		printf("1 %d\n",h+2);
		for(int i=h+2;i<=d;i++) printf("%d %d\n",i,i+1);
	}
	for(int i=d+2;i<=n;i++) printf("%d %d\n",h==1?1:2,i);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}