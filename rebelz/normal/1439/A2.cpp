#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
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

struct node{
	int x1,y1,x2,y2,x3,y3;
	node(int x1=0,int y1=0,int x2=0,int y2=0,int x3=0,int y3=0):x1(x1),y1(y1),x2(x2),y2(y2),x3(x3),y3(y3){}
};

int n,m;
char s[105][105];
int a[105][105];
vector<node> ans;

void operate(int x1,int y1,int x2,int y2,int x3,int y3){
	a[x1][y1]^=1,a[x2][y2]^=1,a[x3][y3]^=1;
	ans.pb(node(x1,y1,x2,y2,x3,y3));
}

void dfs(){
	vector<pii> vec(0),tmp(0);
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			if(a[n-i][m-j]) vec.pb(mp(n-i,m-j));
			else tmp.pb(mp(n-i,m-j));
		}
	}
	if(!vec.size()) return;
	if(vec.size()==3) return operate(vec[0].fi,vec[0].se,vec[1].fi,vec[1].se,vec[2].fi,vec[2].se);
	else if(vec.size()==1){
		if(vec[0]==mp(n,m)) operate(n,m,n-1,m,n-1,m-1);
		else if(vec[0]==mp(n,m-1)) operate(n,m-1,n,m,n-1,m);
		else if(vec[0]==mp(n-1,m)) operate(n-1,m,n,m,n,m-1);
		else if(vec[0]==mp(n-1,m-1)) operate(n-1,m-1,n,m-1,n,m);
		dfs();
	}
	else if(vec.size()==2){
		if(abs(vec[0].fi-vec[1].fi)==abs(vec[0].se-vec[1].se)) operate(vec[0].fi,vec[0].se,vec[1].fi,vec[1].se,tmp[0].fi,tmp[0].se);
		else operate(vec[0].fi,vec[0].se,tmp[0].fi,tmp[0].se,tmp[1].fi,tmp[1].se);
		dfs();
	}
	else{
		operate(vec[0].fi,vec[0].se,vec[1].fi,vec[1].se,vec[2].fi,vec[2].se);
		dfs();
	}
}

int main(){
	int T=readint();
	while(T--){
		ans.clear();
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=s[i][j]-'0';
		for(int i=1;i<=n-2;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]){
					if(j<m) operate(i,j,i+1,j,i+1,j+1);
					else operate(i,j,i+1,j,i+1,j-1);
				}
			}
		}
		for(int i=1;i<=m-2;i++){
			if(a[n-1][i]) operate(n-1,i,n-1,i+1,n,i+1);
			if(a[n][i]) operate(n,i,n,i+1,n-1,i+1);
		}
		dfs();
		printf("%d\n",ans.size());
		for(auto r:ans) printf("%d %d %d %d %d %d\n",r.x1,r.y1,r.x2,r.y2,r.x3,r.y3);
	}
	return 0;
}