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
const int maxn=100+5,maxd=2e3+5;
int n,t[maxn],d[maxn],p[maxn];
int ord[maxn];
int dp[maxn][maxd];
bool c[maxn][maxd];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++){
		t[i]=readint();
		d[i]=readint();
		p[i]=readint();
	}
	for(int i=1;i<=n;i++) ord[i]=i;
	sort(ord+1,ord+n+1,[](int a,int b){
		return d[a]<d[b];
	});
	for(int i=n;i>0;i--) for(int j=0;j<maxd;j++){
		if(j+t[ord[i]]>=d[ord[i]]||dp[i+1][j]>dp[i+1][j+t[ord[i]]]+p[ord[i]]){
			dp[i][j]=dp[i+1][j];
			c[i][j]=0;
		}
		else{
			dp[i][j]=dp[i+1][j+t[ord[i]]]+p[ord[i]];
			c[i][j]=1;
		}
	}
	printf("%d\n",dp[1][0]);
	int u=0;
	vector<int> s;
	for(int i=1;i<=n;i++) if(c[i][u]){
		s.push_back(ord[i]);
		u+=t[ord[i]];
	}
	printf("%d\n",(int)s.size());
	for(int i:s) printf("%d ",i);
	return 0;
}