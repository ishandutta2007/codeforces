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
int d[5005][5005];
char s[5005],t[5005];

int main(){
	n=readint(); m=readint();
	scanf("%s%s",s+1,t+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			d[i][j]=max(d[i-1][j]-1,d[i][j-1]-1);
			if(s[i]==t[j]) chkmax(d[i][j],d[i-1][j-1]+2);
			else chkmax(d[i][j],d[i-1][j-1]-2);
			chkmax(d[i][j],0);
			chkmax(ans,d[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}