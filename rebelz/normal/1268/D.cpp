#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,ncnt,scnt;
int a[2005][2005],dfn[2005],low[2005],du[2005],tmp[2005];
char str[2005];
bool ins[2005];
stack<int> s;

void tarjan(int u){
	dfn[u]=low[u]=++ncnt;
	s.push(u); ins[u]=1;
	for(int i=1;i<=n;i++){
		if(!a[u][i]) continue;
		if(!dfn[i]) tarjan(i),chkmin(low[u],low[i]);
		else if(ins[i]) chkmin(low[u],dfn[i]);
	}
	if(dfn[u]==low[u]){
		scnt++;
		while(s.top()!=u) ins[s.top()]=0,s.pop();
		ins[u]=0,s.pop();
	}
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++){
		scanf("%s",str+1);
		for(int j=1;j<=n;j++) a[i][j]=str[j]-'0';
	}
	if(n<=6){
		int ans=1<<30; ll ansval=0;
		for(int i=0;i<(1<<n);i++){
			int cnt=0;
			for(int j=1;j<=n;j++){
				if((i>>(j-1))&1){
					for(int k=1;k<=n;k++) a[j][k]^=1,a[k][j]^=1;
					cnt++;
				}
			}
			memset(dfn,0,sizeof(dfn));
			scnt=ncnt=0;
			for(int j=1;j<=n;j++) if(!dfn[j]) tarjan(j);
			if(scnt==1){
				if(chkmin(ans,cnt)) ansval=1;
				else if(ans==cnt) ansval++;
			}
			for(int j=1;j<=n;j++)
				if((i>>(j-1))&1)
					for(int k=1;k<=n;k++) a[j][k]^=1,a[k][j]^=1;
		}
		for(int i=1;i<=ans;i++) ansval=ansval*i;
		if(ans==(1<<30)) printf("-1\n");
		else printf("%d %lld\n",ans,ansval);
	}
	else{
		int cnt=0;
		for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
		if(scnt==1) return printf("0 1\n"),0;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(a[i][j]) du[i]++;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]) du[i]--,du[j]++;
				else du[i]++,du[j]--;
				a[i][j]^=1,a[j][i]^=1;
			}
			memcpy(tmp,du,sizeof(tmp));
			sort(tmp+1,tmp+n+1);
			bool fl=1;
			int sum=0;
			for(int j=1;j<n;j++){
				sum+=tmp[j];
				if(sum==j*(j-1)/2) fl=0;
			}
			cnt+=fl;
			for(int j=1;j<=n;j++){
				if(a[i][j]) du[i]--,du[j]++;
				else du[i]++,du[j]--;
				a[i][j]^=1,a[j][i]^=1;
			}
		}
		printf("1 %d\n",cnt);
	}
	return 0;
}