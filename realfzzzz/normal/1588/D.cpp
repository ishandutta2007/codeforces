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
const int maxn=10;
int n,p[maxn+5][2][52];
char s[150];
int ecd(char c){
	if(islower(c)) return c-'a';
	else return c-'A'+26;
}
char dcd(int c){
	if(c<26) return c+'a';
	else return c-26+'A';
}
int f[52][(1<<maxn)+5],d1[52][(1<<maxn)+5],d2[52][(1<<maxn)+5];
int dfs(int c,int s){
	if(f[c][s]>=0) return f[c][s];
	f[c][s]=1;
	d1[c][s]=-1;
	for(int i=0;i<52;i++){
		int s2=0;
		for(int j=0;j<n;j++){
			if(!p[j][0][i]) s2=-1;
			else if(p[j][1][i]){
				if(p[j][1][i]<=p[j][s>>j&1][c]) s2=-1;
				else if(p[j][0][i]<=p[j][s>>j&1][c]) s2|=1<<j;
			}
			else if(p[j][0][i]<=p[j][s>>j&1][c]) s2=-1;
			if(s2<0) break;
		}
		if(s2>=0&&f[c][s]<dfs(i,s2)+1){
			f[c][s]=dfs(i,s2)+1;
			d1[c][s]=i;
			d2[c][s]=s2;
		}
	}
	return f[c][s];
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		memset(p,0,sizeof(p));
		for(int i=0;i<n;i++){
			scanf("%s",s+1);
			int l=strlen(s+1);
			for(int j=1;j<=l;j++)
				if(!p[i][0][ecd(s[j])]) p[i][0][ecd(s[j])]=j;
				else p[i][1][ecd(s[j])]=j;
		}
		memset(f,-1,sizeof(f));
		int ans=0,c=-1,s=0;
		for(int i=0;i<52;i++){
			bool flag=1;
			for(int j=0;j<n;j++) flag&=(bool)p[j][0][i];
			if(flag&&ans<dfs(i,0)){
				ans=dfs(i,0);
				c=i;
			}
		}
		printf("%d\n",ans);
		while(c>=0){
			printf("%c",dcd(c));
			int c2=d1[c][s],s2=d2[c][s];
			c=c2;
			s=s2;
		}
		printf("\n");
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}