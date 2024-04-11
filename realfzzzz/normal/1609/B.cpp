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
const int maxn=1e5+5;
int n,q;
char s[maxn];
bool check(int x){
	return s[x]=='a'&&s[x+1]=='b'&&s[x+2]=='c';
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	q=readint();
	scanf("%s",s+1);
	int cnt=0;
	for(int i=1;i<=n-2;i++) cnt+=check(i);
	while(q--){
		int x=readint();
		char c[5];
		scanf("%s",c);
		cnt-=check(x);
		if(x>1) cnt-=check(x-1);
		if(x>2) cnt-=check(x-2);
		s[x]=c[0];
		cnt+=check(x);
		if(x>1) cnt+=check(x-1);
		if(x>2) cnt+=check(x-2);
		printf("%d\n",cnt);
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}