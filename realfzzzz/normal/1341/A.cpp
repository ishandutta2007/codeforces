#include<cstring>
#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
	int x=0;
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
	int t=readint();
	while(t--){
		int n,a,b,c,d;
		n=readint();
		a=readint();
		b=readint();
		c=readint();
		d=readint();
		if(n*(a+b)<c-d||n*(a-b)>c+d) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}