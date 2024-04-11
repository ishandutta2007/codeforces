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
const int maxn=64+5,maxm=256+5;
int n,m,c[maxm],g[maxn][maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		m=readint();
		memset(g,-1,sizeof(g));
		for(int i=0;i<m;i++){
			int a,b;
			a=readint();
			b=readint();
			c[i]=readint();
			g[a][b]=g[b][a]=i;
		}
		vector<vector<int>> a;
		for(int i=0;i<m;i++) if(c[i]>=0){
			a.push_back(vector<int>(m+1));
			a.back()[i]=1;
			a.back()[m]=c[i]%3;
		}
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(g[i][j]>=0)
			for(int k=j+1;k<=n;k++) if(g[i][k]>=0&&g[j][k]>=0){
				a.push_back(vector<int>(m+1));
				a.back()[g[i][j]]=a.back()[g[i][k]]=a.back()[g[j][k]]=1;
			}
		int r=0;
		vector<int> vec;
		for(int i=0;i<m;i++){
			bool flag=0;
			for(int j=r;j<(int)a.size();j++) if(a[j][i]){
				swap(a[r],a[j]);
				flag=1;
				break;
			}
			if(!flag) continue;
			vec.push_back(i);
			for(int j=r+1;j<(int)a.size();j++) if(a[j][i]){
				int t=a[j][i]*a[r][i]%3;
				for(int k=i;k<=m;k++) a[j][k]=(a[j][k]-a[r][k]*t%3+3)%3;
			}
			r++;
		}
		memset(c,0,sizeof(c));
		for(int i=r-1;i>=0;i--){
			int s=a[i][m];
			for(int j=vec[i]+1;j<m;j++) s=(s-c[j]*a[i][j]%3+3)%3;
			c[vec[i]]=s*a[i][vec[i]]%3;
		}
		bool flag=1;
		for(int i=r;i<(int)a.size();i++){
			int s=0;
			for(int j=0;j<m;j++) s=(s+c[i]*a[i][j]%3)%3;
			flag&=s==a[i][m];
		}
		if(flag){
			for(int i=0;i<m;i++) printf("%d ",c[i]?c[i]:3);
			printf("\n");
		}
		else printf("-1\n");
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}