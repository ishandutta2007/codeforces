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
const int inf=0x3f3f3f3f;
const int pw[7]={1,5,25,125,625,3125,15625};
int a[10],b[10],val[10][10],d[10][10][16000][10];

int main(){
	n=readint(); m=readint();
	int tmp=0;
	for(int i=1;i<=n;i++) a[i]=readint(),tmp+=a[i];
	for(int i=1;i<=m;i++) b[i]=readint(),tmp-=b[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) val[i][j]=readint();
	if(tmp>0) return printf("-1\n"),0;
	memset(d,0x3f,sizeof(d));
	d[0][n][0][0]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<pw[n];j++) for(int k=0;k<=b[i-1];k++) chkmin(d[i][0][j][0],d[i-1][n][j][k]);
		for(int j=1;j<=n;j++){
			for(int k=0;k<pw[n];k++){
				for(int l=0;l<=b[i];l++){
					if(d[i][j-1][k][l]>=inf) continue;
					chkmin(d[i][j][k][l],d[i][j-1][k][l]);
					int flow=min(a[j]-k/pw[j-1]%5,b[i]-l);
					for(int f=0;f<=flow;f++) chkmin(d[i][j][k+f*pw[j-1]][l+f],d[i][j-1][k][l]+val[j][i]);
				}
			}
		}	
	}
	int ans=inf,mask=0;
	for(int i=1;i<=n;i++) mask+=a[i]*pw[i-1];
	for(int i=0;i<=b[m];i++) chkmin(ans,d[m][n][mask][i]);
	printf("%d\n",ans);
	return 0;
}