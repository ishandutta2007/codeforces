#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int N=100000;
int n,top,ans=1<<30;
int m[20],k[20],ak[20],a[20][100005],b[20][100005];
bool vis[200005];

void dfs(int now){
	if(now>=19) return;
	if(!m[top]){
		int ncnt=0;
		for(int i=1;i<=top;i++) if(k[i]) ncnt++;
		if(ncnt<ans) ans=ncnt,memcpy(ak,k,sizeof(ak));
		return;
	}
	int cm=0;
	for(int i=1;i<=m[top];i++) if(a[top][i]&&!vis[a[top][i]+N]) vis[a[top][i]+N]=true,b[top][++cm]=a[top][i];
	for(int i=1;i<=m[top];i++) vis[a[top][i]+N]=false;
	bool fl=false;
	for(int i=1;i<=cm;i++) if(b[top][i]%2!=0) fl=true;
	if(!fl){
		m[++top]=cm;
		k[top]=0;
		for(int i=1;i<=cm;i++) a[top][i]=b[top-1][i]/2;
		dfs(now+1);
		top--;
		return;
	}
	m[++top]=0;
	for(int i=1;i<=cm;i++){
		if(b[top-1][i]%2!=0&&b[top-1][i]!=1) a[top][++m[top]]=(b[top-1][i]-1)/2;
		else if(b[top-1][i]%2==0) a[top][++m[top]]=b[top-1][i]/2;
	}
	k[top]=1;
	dfs(now+1);
	m[top]=0;
	for(int i=1;i<=cm;i++){
		if(b[top-1][i]%2!=0&&b[top-1][i]!=-1) a[top][++m[top]]=(b[top-1][i]+1)/2;
		else if(b[top-1][i]%2==0) a[top][++m[top]]=b[top-1][i]/2;
	}
	k[top]=-1;
	dfs(now+1);
	k[top--]=0;
}

int main(){
	m[0]=n=readint();
	for(int i=1;i<=n;i++) a[0][i]=readint();
	dfs(0);
	printf("%d\n",ans);
	for(int i=1;i<=19;i++) if(ak[i]) printf("%d ",ak[i]*(1<<(i-1)));
	printf("\n");
	return 0;
}