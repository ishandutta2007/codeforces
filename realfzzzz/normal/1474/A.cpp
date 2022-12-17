#include<bits/stdc++.h>
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
const int maxn=1e5+5;
int n;
char b[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		scanf("%s",b);
		int lst=1;
		printf("1");
		for(int i=1;i<n;i++)
			if(b[i]-'0'+1==b[i-1]-'0'+lst) printf("%d",lst=0);
			else printf("%d",lst=1);
		printf("\n");
	}
	return 0;
}