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

bool chkmin(int &x,int y){return x>y?x=y,1:0;}
bool chkmax(int &x,int y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1019260817;
int n,m;
char s[1000005];
vector<int> tmp;
vector<vector<int> > a,d,f;

int mod(int x){return x>=cys?x-cys:x;}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++) tmp.push_back(0);
	for(int i=1;i<=n;i++) a.push_back(tmp),d.push_back(tmp),f.push_back(tmp);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		for(int j=0;j<m;j++) a[i][j]=s[j]!='.';
	}
	d[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==1) continue;
			if(i) d[i][j]=mod(d[i][j]+d[i-1][j]);
			if(j) d[i][j]=mod(d[i][j]+d[i][j-1]);
		}
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++) cout<<d[i][j]<<' ';
//		cout<<endl;
//	}
	f[n-1][m-1]=1;
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			if(a[i][j]==1) continue;
			if(i<n-1) f[i][j]=mod(f[i][j]+f[i+1][j]);
			if(j<m-1) f[i][j]=mod(f[i][j]+f[i][j+1]);
		}
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++) cout<<f[i][j]<<' ';
//		cout<<endl;
//	}
	if(!d[n-1][m-1]) return printf("0\n"),0;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if((i!=0||j!=0)&&(i!=n-1||j!=m-1)&&d[n-1][m-1]==1ll*d[i][j]*f[i][j]%cys) return printf("1\n"),0;
	printf("2\n");
	return 0;
}