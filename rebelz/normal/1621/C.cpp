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
int ans[10005];
bool vis[10005];

int query(int x){
	printf("? %d\n",x);
	fflush(stdout);
	return readint();
}

void solve(int x){
	int st=query(x);
	vector<int> vec(1,st);
	while(1){
		int tmp=query(x);
		vec.pb(tmp);
		if(tmp==st) break;
	}
	for(int i=0;i<vec.size()-1;i++) ans[vec[i]]=vec[i+1],vis[vec[i]]=1;
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=n;i++) if(!vis[i]) solve(i);
		printf("! ");
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");
		fflush(stdout);
	}
	return 0;
}