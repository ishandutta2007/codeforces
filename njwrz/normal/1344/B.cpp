#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
bool a[1005][1005],f[1005][1005],cnt[2][1005];
int n,m;
bool U[1005][1005],D[1005][1005],L[1005][1005],R[1005][1005],cnt1[2][1005];
void dfs(int x,int y){
	int tx,ty;
	a[x][y]=0;
	if(L[x][y]){
		tx=x;ty=y-1;
		if(a[tx][ty])dfs(tx,ty);
	}
	if(R[x][y]){
		tx=x;ty=y+1;
		if(a[tx][ty])dfs(tx,ty);
	}
	if(U[x][y]){
		tx=x-1;ty=y;
		if(a[tx][ty])dfs(tx,ty);
	}
	if(D[x][y]){
		tx=x+1;ty=y;
		if(a[tx][ty])dfs(tx,ty);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	char c;
	FOR(i,1,n){
		FOR(j,1,m){
			cin>>c;
			if(c=='#'){
				a[i][j]=1;
				cnt1[0][i]=1;
				cnt1[1][j]=1;
			}
		}
	}
	FOR(i,1,n){
		int l=m+1,r=0;
		FOR(j,1,m)if(a[i][j]){
			gmin(l,j);gmax(r,j);
		}
		if(l==m+1)continue;
		bool anf=1;
		FOR(j,1,m){
			if(!a[i][j]&&j>=l&&j<=r){
				anf=0;break;
			}
		}
		if(anf){
			FOR(j,1,m)f[i][j]=a[i][j];
		}
	}
	FOR(i,1,m){
		int l=n+1,r=0;
		FOR(j,1,n)if(a[j][i]){
			gmin(l,j);gmax(r,j);
		}
		if(l==n+1)continue;
		bool anf=1;
		FOR(j,1,n){
			if(!a[j][i]&&j>=l&&j<=r){
				anf=0;break;
			}
		}
		if(anf){
			FOR(j,1,m)f[i][j]&=a[i][j];
		}else FOR(j,1,m)f[i][j]=0;
	}
	FOR(i,1,n){
		FOR(j,1,m){
			if(!cnt1[0][i]&&!cnt1[1][j])f[i][j]=1;
			if(f[i][j]){
				cnt[0][i]=1;
				cnt[1][j]=1;
			}
		}
	}
	FOR(i,1,n)if(cnt[0][i]==0){
		cout<<-1;RE 0;
	}
	FOR(i,1,m)if(cnt[1][i]==0){
		cout<<-1;RE 0;
	}
	FOR(i,1,m){
		U[1][i]=0;
		FOR(j,2,n){
			if(a[j-1][i])U[j][i]=1;
			else U[j][i]=U[j-1][i];
		}
		D[n][i]=0;
		for(int j=n-1;j>=1;j--){
			if(a[j+1][i])D[j][i]=1;
			else D[j][i]=D[j+1][i];
		}
	}
	FOR(i,1,n){
		L[i][1]=0;
		FOR(j,2,m){
			if(a[i][j-1])L[i][j]=1;
			else L[i][j]=L[i][j-1];
		}
		R[i][m]=0;
		for(int j=m-1;j>=1;j--){
			if(a[i][j+1])R[i][j]=1;
			else R[i][j]=R[i][j+1]; 
		} 
	}
	int ans=0;
	FOR(i,1,n){
		FOR(j,1,m)if(a[i][j]){
			dfs(i,j);ans++;
		}
	}
	cout<<ans;
	RE 0;
}