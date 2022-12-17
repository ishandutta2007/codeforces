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
ll pw[18];
int sz=1,ch[maxn*18][2],val[maxn*18];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	pw[0]=1;
	for(int i=1;i<18;i++) pw[i]=pw[i-1]*10;
	while(n--){
		char opt[5];
		scanf("%s",opt);
		if(opt[0]=='+'||opt[0]=='-'){
			ll a=read();
			int u=1;
			for(int i=0;i<18;i++){
				bool c=a/pw[i]%2;
				if(!ch[u][c]) ch[u][c]=++sz;
				u=ch[u][c];
			}
			val[u]+=opt[0]=='+'?1:-1;
		}
		else{
			char s[20];
			scanf("%s",s);
			int l=strlen(s),u=1;
			for(int i=0;i<18;i++)
				u=ch[u][i<l?s[l-i-1]-'0':0];
			printf("%d\n",val[u]);
		}
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}