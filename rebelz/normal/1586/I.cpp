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

int n;
int a[2005][2005],res[1005];
char s[2005][2005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	if(n&1){
		printf("NONE\n");
		return 0;
	}
	n>>=1;
	for(int i=1;i<=n;i++) a[i][i]=i;
	for(int i=n+1;i<=n+n;i++) a[i][i]=n+n-i+1;
	for(int i=2;i<=n+n;i++){
		if(i&1){
			for(int j=i;j<=n+n;j++) a[j][j-i+1]=-a[j-1][j-i+2];
		}
		else{
			a[i][1]=a[i-1][1];
			for(int j=i+1;j<=n+n;j++) a[j][j-i+1]=-a[j-1][j-i];
		}
	}
	for(int i=1;i<=n+n;i++) for(int j=i+1;j<=n+n;j++) a[i][j]=a[j][i];
	for(int i=1;i<=n+n;i++) res[i]=-1;
	for(int i=1;i<=n+n;i++){
		for(int j=1;j<=n+n;j++){
			if(s[i][j]!='.'){
				int fl=s[i][j]=='S';
				if(a[i][j]<0) fl^=1;
				if(res[abs(a[i][j])]>=0&&res[abs(a[i][j])]!=fl) return printf("NONE\n"),0;
				res[abs(a[i][j])]=fl;
			}
		}
	}
	for(int i=1;i<=n;i++) if(res[i]<0) return printf("MULTIPLE\n"),0;
	printf("UNIQUE\n");
	for(int i=1;i<=n+n;i++){
		for(int j=1;j<=n+n;j++){
			if(a[i][j]<0) putchar(res[-a[i][j]]?'G':'S');
			else putchar(res[a[i][j]]?'S':'G');
		}
		putchar('\n');
	}
	return 0;
}