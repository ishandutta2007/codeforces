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
const int maxn=2.3e5,maxm=16+5;
int n,m,a[maxm],b[maxn][maxm];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		m=read();
		for(int i=1;i<=m;i++) a[i]=read();
		vector<int> vec;
		for(int i=1;i<=m;i++) if(a[i]>1) vec.push_back(i);
		bool flag=1;
		if(vec.size()>2) flag=0;
		else if(vec.size()==2) flag=a[vec[0]]==2&&a[vec[1]]==2;
		else if(vec.size()==1) flag=a[vec[0]]<=3;
		if(!flag){
			printf("-1\n");
			continue;
		}
		if(vec.size()==1&&a[vec[0]]==3){
			n=4;
			for(int i=1;i<=n;i++) memset(b[i],0,sizeof(b[i]));
			int x=vec[0];
			b[3][x]=1;
			b[4][x]=2;
			b[2][x]=3;
			for(int i=1;i<=m;i++) if(a[i]==1){
				for(int j=n+1;j<=n*2;j++) memcpy(b[j],b[j-n],sizeof(b[j]));
				for(int j=2;j<=n;j+=2) b[j][i]=1;
				for(int j=n+1;j<=n*2;j+=2) b[j][i]=1;
				swap(b[n/2+1],b[n+1]);
				n*=2;
			}
		}
		else{
			if(vec.size()==2){
				n=9;
				for(int i=1;i<=n;i++) memset(b[i],0,sizeof(b[i]));
				int x=vec[0],y=vec[1];
				b[3][y]=b[4][y]=b[6][x]=b[6][y]=b[8][x]=b[9][x]=1;
				b[2][x]=b[2][y]=b[4][x]=b[5][y]=b[7][x]=b[8][y]=2;
			}
			else if(vec.size()==1){
				n=3;
				for(int i=1;i<=n;i++) memset(b[i],0,sizeof(b[i]));
				int x=vec[0];
				b[3][x]=1;
				b[2][x]=2;
			}
			else{
				n=2;
				for(int i=1;i<=n;i++) memset(b[i],0,sizeof(b[i]));
				b[2][1]=1;
			}
			for(int i=vec.size()?1:2;i<=m;i++) if(a[i]==1){
				for(int j=n+1;j<=n*2;j++) memcpy(b[j],b[n*2-j+1],sizeof(b[j]));
				for(int j=3;j<=n*2;j+=2) b[j][i]=1;
				b[n*2][i]=1;
				n*=2;
			}
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=m;j++) printf("%d ",b[i][j]);
			printf("\n");
		}
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}