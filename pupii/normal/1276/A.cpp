#include<bits/stdc++.h>
#define vd void
#define il inline
using namespace std;
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
#ifdef mod
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
#endif
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int T=gi();
	while(T--){
		static char s[150010];
		scanf("%s",s+1);int n=strlen(s+1);
		std::vector<int>del;
		for(int j=3;j<=n;++j){
			if(s[j-2]=='o'&&s[j-1]=='n'&&s[j]=='e'){
				if(s[j+1]=='e')s[j-1]='&',del.push_back(j-1);
				else s[j]='&',del.push_back(j);
			}
			if(s[j-2]=='t'&&s[j-1]=='w'&&s[j]=='o'){
				if(s[j+1]=='o')s[j-1]='&',del.push_back(j-1);
				else s[j]='&',del.push_back(j);
			}
		}
		printf("%d\n",del.size());
		for(int i:del)printf("%d ",i);
		puts("");
	}
	return 0;
}