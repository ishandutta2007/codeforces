#include<bits/stdc++.h>
using namespace std;
using ll=long long;
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
const int maxn=1e5+5;
int n;
char a[maxn*2];
bool c[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		scanf("%s",a+1);
		int s=0,cnt=0;
		c[1]=0;
		for(int i=1;i<=n*2;i++)
			if(a[i]=='('){
				if(!c[++s]) cnt++;
				c[s]=1;
			}
			else c[(s--)+1]=0;
		printf("%d\n",cnt);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}