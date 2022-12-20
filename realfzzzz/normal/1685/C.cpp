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
int n,s[maxn*2];
char a[maxn*2];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		scanf("%s",a+1);
		for(int i=1;i<=n*2;i++) s[i]=s[i-1]+(a[i]=='('?1:-1);
		int l=1,r=n*2;
		while(l<=n*2&&s[l]>=0) l++;
		while(r&&s[r]>=0) r--;
		if(l>n*2){
			printf("0\n");
			continue;
		}
		int l2=1,r2=r;
		for(int i=2;i<=l;i++) if(s[i-1]>s[l2-1]) l2=i;
		for(int i=r+1;i<=n*2;i++) if(s[i]>s[r2]) r2=i;
		bool flag=1;
		for(int i=l2-1;i<r2;i++) flag&=s[l2-1]+s[r2]>=s[i];
		if(flag) printf("1\n%d %d\n",l2,r2);
		else{
			int mx=1;
			for(int i=2;i<=n*2;i++) if(s[i]>s[mx]) mx=i;
			printf("2\n1 %d\n%d %d\n",mx,mx+1,n*2);
		}
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}