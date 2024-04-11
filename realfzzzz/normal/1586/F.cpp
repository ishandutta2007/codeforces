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
const int maxn=1e3+5;
int n,k,c[maxn][maxn],ans=0;
void solve(int L,int R,int d){
	ans=max(ans,d);
	if(R-L+1<=k){
		for(int i=L;i<=R;i++) for(int j=i+1;j<=R;j++) c[i][j]=d;
		return;
	}
	int s=(R-L)/k+1;
	for(int i=1;i<=k;i++){
		int l=L+s*(i-1),r=min(L+s*i-1,R);
		for(int j=l;j<=r;j++) for(int h=r+1;h<=R;h++) c[j][h]=d;
		solve(l,r,d+1);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	k=readint();
	solve(1,n,1);
	printf("%d\n",ans);
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) printf("%d ",c[i][j]);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}