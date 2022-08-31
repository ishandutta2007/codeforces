#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,R,cnt;
ll now[1000005],nrt[1000005],ans[1000005],opt[1000005],pl[1000005];
char s[1000005],tp[1000005],chr[1000005];
vector<int> adj[1000005];

int dfs(int u){
	if(!adj[u].size()) return 1;
	int ret=0;
	for(auto v:adj[u]){
		if(chr[u]=='S'){
			int tmp=dfs(v);
			if(!ret) ret=tmp,opt[u]=v;
			else if(chkmin(ret,tmp)) opt[u]=v;
		}
		else if(chr[u]=='P'){
			ret+=dfs(v);
		}
	}
	return ret;
}

void getans(int u){
	if(!adj[u].size()){
		ans[pl[u]]=R*now[0];
		return;
	}
	if(chr[u]=='P'){
		for(auto v:adj[u]) getans(v);
	}
	else getans(opt[u]);
}

int main(){
	int T=readint();
	while(T--){
		R=readint();
		char ch=getchar();
		n=cnt=0;
		int dep=0;
		while(ch!='\n'){
			if(ch!=' ') s[++n]=ch;
			ch=getchar();
		}
		chr[0]='P';
		for(int i=1;i<=n;i++){
			if(s[i]=='('){
				adj[nrt[dep]].push_back(i);
				dep++;
				now[dep]=0;
				nrt[dep]=i;
			}
			else if(s[i]==')'){
				if(!now[dep-1]) now[dep-1]=now[dep];
				else if(tp[dep-1]=='S') chkmin(now[dep-1],now[dep]);
				else if(tp[dep-1]=='P') now[dep-1]+=now[dep];
				chr[nrt[dep]]=tp[dep];
				dep--;
			}
			else if(s[i]=='*'){
				pl[i]=++cnt;
				adj[nrt[dep]].push_back(i);
				if(!now[dep]) now[dep]=1;
				else if(tp[dep]=='S') chkmin(now[dep],1ll);
				else if(tp[dep]=='P') now[dep]++;
			}
			else if(s[i]=='S') tp[dep]='S';
			else if(s[i]=='P') tp[dep]='P';
		}
		dfs(0);
		getans(0);
		printf("REVOLTING ");
		for(int i=1;i<=cnt;i++) printf("%lld ",ans[i]);
		printf("\n");
		for(int i=0;i<=cnt;i++) ans[i]=0;
		for(int i=0;i<=n;i++) tp[i]=0,now[i]=0,opt[i]=0,nrt[i]=0,pl[i]=0,tp[i]=0,chr[i]=0;
		for(int i=0;i<=n;i++) adj[i].clear();
	}
	return 0;
}