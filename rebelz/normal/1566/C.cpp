// xtqqwq
#include<bits/stdc++.h>

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
int d[100005][4],a[4],b[100005];
char s[2][100005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		scanf("%s",s[0]+1);
		scanf("%s",s[1]+1);
		for(int i=0;i<=n;i++) d[i][0]=d[i][1]=d[i][2]=d[i][3]=-0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			b[i]=0;
			if(s[0][i]=='0'||s[1][i]=='0') b[i]|=1;
			if(s[0][i]=='1'||s[1][i]=='1') b[i]|=2;
		}
		d[0][0]=0;
		a[0]=0,a[1]=1,a[2]=0,a[3]=2;
		for(int i=1;i<=n;i++){
			for(int j=0;j<4;j++){
				chkmax(d[i][j|b[i]],d[i-1][j]);
				chkmax(d[i][0],d[i-1][j]+a[j|b[i]]);
			}
		}
		printf("%d\n",d[n][0]);
	}
	return 0;
}