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

int n,m;
vector<int> ans[100005],tmp[100005];

int id(int x,int y){return (x-1)*m+y;}

int gett(int id){
	int x=(id-1)/m+1,y=(id-1)%m+1;
	return (y-1)*n+x;
}

int main(){
	n=readint(); m=readint();
	bool fl=0;
	if(n>m) swap(n,m),fl=1;
	if(n==1&&m==1){
		printf("YES\n");
		printf("1\n");
		return 0;
	}
	if(n==3&&m==3){
		printf("YES\n");
		printf("2 9 4\n8 1 3\n6 7 5\n");
		return 0;
	}
	if(n<=3&&m<=3) return printf("NO\n"),0;
	printf("YES\n");
	for(int i=1;i<=n;i++){
		int t=0;
		if(m%2==0){
			if(i&1){
				for(int j=2;j<=m;j+=2) ans[i].pb(id(i,j));
				for(int j=1;j<=m;j+=2) ans[i].pb(id(i,j));
			}
			else{
				for(int j=m-1;j>=1;j-=2) ans[i].pb(id(i,j));
				for(int j=m;j>=2;j-=2) ans[i].pb(id(i,j));
			}
		}
		else{
			if(i&1){
				for(int j=1;j<=m;j+=2) ans[i].pb(id(i,j));
				for(int j=2;j<=m;j+=2) ans[i].pb(id(i,j));
			}
			else{
				for(int j=2;j<=m;j+=2) ans[i].pb(id(i,j));
				for(int j=1;j<=m;j+=2) ans[i].pb(id(i,j));
			}
		}
	}
	if(fl){
		for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) tmp[i].pb(gett(ans[j][i-1]));
		swap(ans,tmp);
		swap(n,m);
	}
	for(int i=1;i<=n;i++){
		for(auto x:ans[i]) printf("%d ",x);
		printf("\n");
	}
	return 0;
}