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

int n,m;
int p[100005],b[100005],ans[100005];
vector<int> a[100005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=m;i++){
			a[i].resize(readint());
			for(int j=0;j<a[i].size();j++) a[i][j]=readint();
		}
		for(int i=1;i<=m;i++) p[i]=i;
		sort(p+1,p+m+1,[&](int x,int y){return a[x].size()<a[y].size();});
		for(int i=1;i<=n;i++) b[i]=0;
		bool fl=0;
		for(int i=1;i<=m;i++){
			int mina=1<<30,opt=0;
			for(auto r:a[p[i]]) if(chkmin(mina,b[r])) opt=r;
			b[opt]++;
			if(b[opt]>(m+1)/2) fl=1;
			ans[p[i]]=opt;
		}
		if(fl){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=1;i<=m;i++) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}