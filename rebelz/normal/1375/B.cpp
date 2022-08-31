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
int a[305][305],d[305][305];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=readint();
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) d[i][j]=(i>1)+(i<n)+(j>1)+(j<m);
		bool fl=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]>d[i][j]) fl=1;
		if(fl) printf("NO\n");
		else{
			printf("YES\n");
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++) printf("%d ",d[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
}