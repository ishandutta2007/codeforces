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
const int maxn=1e6+6;
int n,m,q;
char tmp[maxn];
vector<char> s[maxn];
int c[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	for(int i=1;i<=n;i++){
		s[i].resize(m+1);
		scanf("%s",tmp+1);
		for(int j=1;j<=m;j++) s[i][j]=tmp[j];
	}
	for(int i=2;i<=n;i++) for(int j=2;j<=m;j++)
		if(s[i-1][j]=='X'&&s[i][j-1]=='X') c[j]++;
	for(int i=2;i<=m;i++) c[i]+=c[i-1];
	q=readint();
	while(q--){
		int l,r;
		l=readint();
		r=readint();
		printf(c[r]-c[l]?"NO\n":"YES\n");
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}