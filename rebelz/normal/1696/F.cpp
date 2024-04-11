// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int dis[105][105],q[105],fr[105],a[105][105][105];
char str[105];
bool vis[105];

bool bfs(int x,int y){
	for(int i=1;i<=n;i++) vis[i]=0;
	int front=0,rear=0;
	vis[x]=vis[y]=1;
	fr[y]=x,fr[x]=y;
	q[rear++]=x,q[rear++]=y;
	while(front<rear){
		int t=q[front++];
		for(int i=1;i<=n;i++){
			if(a[i][fr[t]][t]){
				if(vis[i]) return false;
				vis[i]=1;
				q[rear++]=i;
				fr[i]=t;
			}
		}
	}
	if(rear!=n) return false;
	return true;
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				scanf("%s",str+1);
				for(int k=1;k<=n;k++) a[i][j][k]=a[j][i][k]=str[k]-'0';
			}
		}
		bool can=0;
		for(int i=2;i<=n;i++){
			if(bfs(1,i)){
				for(int j=1;j<=n;j++) for(int k=1;k<=n;k++) dis[j][k]=0x3f3f3f3f;
				for(int j=1;j<=n;j++) dis[j][j]=0;
				for(int j=2;j<=n;j++) dis[j][fr[j]]=dis[fr[j]][j]=1;
				for(int j=1;j<=n;j++)
					for(int k=1;k<=n;k++)
						for(int l=1;l<=n;l++)
							chkmin(dis[k][l],dis[k][j]+dis[j][l]);
				bool fl=0;
				for(int j=1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=1;l<=n;l++)
							if(a[j][k][l]!=(dis[j][l]==dis[k][l])) fl=1;
				if(!fl){
					printf("Yes\n");
					for(int i=2;i<=n;i++) printf("%d %d\n",i,fr[i]);
					can=1;
					break;
				}
			}
		}
		if(!can) printf("No\n");
	}
	return 0;
}