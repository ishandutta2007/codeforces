#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<math.h>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
int read()
{
char c=getchar();int s=0;int x=1;while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}while(c>='0' && c<='9'){s=s*10+c-'0';c=getchar();}return s*x;
}
const int N=19;
const int h=233;
const int mod=998244353;
map<int,int>ma;
int n,st[N],top,a[N][N],f[1<<18][N],g[N][1<<18];
char c[N][N];
void sor(int v[]){
	for(int i=2,k=1;k<(1<<n);i<<=1,k<<=1){
		for(int j=0;j<(1<<n);j+=i){
			for(int l=0;l<k;l++){
				v[j+l+k]+=v[j+l];
			}
		}
	}
}
void sand(int v[]){
	n--;
	for(int i=2,k=1;k<(1<<n);i<<=1,k<<=1){
		for(int j=0;j<(1<<n);j+=i){
			for(int l=0;l<k;l++){
				v[j+l]-=v[j+l+k];
			}
		}
	}
	n++;
}
int tmp[N][1<<18],ans[1<<18];
void dfs(int u,int las,int ha,int st){
	if(u==n){
		int anss=0;
		for(int i=0;i<(1<<n);i++){
			int val=__builtin_popcount(((1<<n)-1)^(i));
			if(val%2==0)anss+=tmp[st-1][i];
			else anss-=tmp[st-1][i];
		}
		ma[ha]=anss;
	//	cout<<"sese"<<ha<<" "<<anss<<endl;
		return ;
	}
	for(int i=las;i<=n-u;i++){
		bool flag=0;
		for(int k=0;k<(1<<n);k++){
			tmp[st][k]=tmp[st-1][k]*g[i][k];
			if(tmp[st][k])flag=1;
		}
		if(!flag)continue;
		dfs(u+i,i,(1ll*ha*h+i)%mod,st+1);
//		for(int k=0;k<(1<<n);k++)tmp[k]=tmp[k]/g[i][k];
	}
}
signed main(){
	n=read();
    for(int i=1;i<=n;i++){
		scanf("%s",c[i]+1);
		f[1<<(i-1)][i]=1;
	}
	for(int i=1;i<(1<<n);i++){
		for(int k=1;k<=n;k++){
			if(f[i][k]){
				for(int j=1;j<=n;j++){
					if(!(i&(1<<(j-1))) and c[k][j]=='1'){
						f[i^(1<<(j-1))][j]+=f[i][k];
					}
				}
		//		cout<<i<<" "<<k<<" "<<f[i][k]<<endl;
			}
		}
	}
	for(int i=1;i<(1<<n);i++){
		int tmp=__builtin_popcount(i);
		for(int k=1;k<=n;k++){
			g[tmp][i]+=f[i][k];
		}
	}
/*	for(int i=1;i<=n;i++){
		for(int k=0;k<(1<<n);k++){
			cout<<g[i][k]<<" ";
		}
		cout<<endl;
	}
	return 0;*/
	for(int i=0;i<(1<<n);i++)tmp[0][i]=1;
	for(int i=1;i<=n;i++)sor(g[i]);
	dfs(0,1,0,1);
	for(int i=0;i<(1<<(n-1));i++){
		top=0;int ff=1;
		for(int k=1;k<n;k++){
			if(i&(1<<(k-1)))ff++;
			else st[++top]=ff,ff=1;
		}
		st[++top]=ff;
		sort(st+1,st+top+1);
		int ha=0;
		for(int k=1;k<=top;k++){
			ha=(1ll*ha*h+st[k])%mod;
		}
		//cout<<"???"<<ha<<endl;
		ans[i]=ma[ha];
	}
	sand(ans);
	for(int i=0;i<(1<<(n-1));i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}