#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int dx[5]={-1,0,0,1,0},dy[5]={0,-1,1,0,0};
int n,m,cnt,id[505][505],s[505][505],ans,sum;
int sz[250001];
char qwq[501];
bool a[505][505];
int b[505][2005],l[505],tp[250001];
inline void dfs(int i,int j){
	id[i][j]=cnt,sz[cnt]++;
	for(int k=0;k<4;k++){
		int x=i+dx[k],y=j+dy[k];
		if(a[x][y]&&!id[x][y]) dfs(x,y);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%s",qwq+1);
		for(int j=1;j<=n;j++) a[i][j]=(qwq[j]=='.');
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(a[i][j]==0);
			if(a[i][j]&&!id[i][j]) cnt++,dfs(i,j);
		}
	for(int i=m;i<=n;i++){
		memset(tp,0,sizeof(tp)),sum=0;
		for(int j=1;j<m;j++){
			l[j]=0;
			for(int k=i-m+1;k<=i;k++){
				for(int t=0;t<5;t++){
					int x=k+dx[t],y=j+dy[t];
					if(id[x][y]) b[j][++l[j]]=id[x][y];
				}
			}
			for(int k=1;k<=l[j];k++){
				if(!tp[b[j][k]]) sum+=sz[b[j][k]];
				tp[b[j][k]]++;
			}
		}
		for(int j=m;j<=n;j++){
			l[j]=0;
			for(int k=i-m+1;k<=i;k++){
				for(int t=0;t<5;t++){
					int x=k+dx[t],y=j+dy[t];
					if(id[x][y]) b[j][++l[j]]=id[x][y];
				}
			}
			for(int k=1;k<=l[j];k++){
				if(!tp[b[j][k]]) sum+=sz[b[j][k]];
				tp[b[j][k]]++;
			}
			for(int k=1;k<=l[j-m];k++){
				tp[b[j-m][k]]--;
				if(!tp[b[j-m][k]]) sum-=sz[b[j-m][k]];
			}
			ans=max(ans,sum+s[i][j]-s[i-m][j]-s[i][j-m]+s[i-m][j-m]);
		}
	}
	cout<<ans;
}