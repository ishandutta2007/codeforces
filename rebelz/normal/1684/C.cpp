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

int n,m;
int a[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) a[(i-1)*m+j]=readint();
		}
		int tx=0,ty=0;
		for(int i=1;i<=n;i++){
			int pl=0,k=(i-1)*m;
			for(int j=1;j<m;j++){
				if(a[k+j]>a[k+j+1]){
					pl=j;
					break;
				}
			}
			if(!pl) continue;
			int tpl=pl;
			while(tpl>1&&a[k+tpl]==a[k+tpl-1]) tpl--;
			int tmp=0;
			for(int j=pl+1;j<=m;j++){
				if(a[k+j]<a[k+pl+1]){
					tmp=j;
					break;
				}
			}
			if(tmp){
				tx=tpl,ty=tmp;
				break;
			}
			for(int j=pl+1;j<=m;j++) if(a[k+j]==a[k+pl+1]) tmp=j;
			tx=tpl,ty=tmp;
			break;
		}
		if(tx){
			for(int i=1;i<=n;i++) swap(a[(i-1)*m+tx],a[(i-1)*m+ty]);
			bool fl=1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<m;j++) if(a[(i-1)*m+j]>a[(i-1)*m+j+1]) fl=0;
			}
			if(fl) printf("%d %d\n",tx,ty);
			else printf("-1\n");
		}
		else printf("1 1\n");
	}
	return 0;
}