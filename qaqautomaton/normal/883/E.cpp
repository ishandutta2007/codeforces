#include<bits/stdc++.h>
inline int read(){
	int x=0,w=1;
	char ch=0;
	while (ch<'0' || ch>'9'){
		ch=getchar();
		if (ch=='-') w=-1;	
	}
	while (ch<='9' && ch>='0'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*w;
}
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m;
bool vis[30],p[30],q[30];
char s[55],c[55];
int main(){
	n=read();
	scanf("%s",s+1);
	memset(p,1,sizeof(p));
	for (int i=1;i<=n;++i)
		if (s[i]!='*') vis[s[i]-'a']=1,p[s[i]-'a']=0;
	m=read();
	for (int i=1;i<=m;++i){
		scanf("%s",c+1);
		int flag=0;
		for (int j=1;j<=n;++j)
			if ((s[j]=='*' && vis[c[j]-'a']) || (s[j]!=c[j] && s[j]!='*')){
				flag=1;break;
			}
		if (flag) continue;
		memset(q,0,sizeof(q));
		for (int j=1;j<=n;++j)
			q[c[j]-'a']=1;
		for (int j=0;j<=25;++j)
			p[j]&=q[j];
	}
	int ans=0;
	for (int i=0;i<=25;++i)
		if (p[i]) ++ans;
	printf("%d\n",ans);
	return 0;
}