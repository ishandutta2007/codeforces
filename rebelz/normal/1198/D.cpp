#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
char a[55][55];
int d[55][55][55][55];

int dp(int x1,int y1,int x2,int y2){
	if(d[x1][y1][x2][y2]>=0) return d[x1][y1][x2][y2];
	int ans=max(y2-y1+1,x2-x1+1);
	for(int i=x1;i<=x2-1;i++) ans=min(ans,dp(x1,y1,i,y2)+dp(i+1,y1,x2,y2));
	for(int i=y1;i<=y2-1;i++) ans=min(ans,dp(x1,y1,x2,i)+dp(x1,i+1,x2,y2));
	d[x1][y1][x2][y2]=ans;
	return ans;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	memset(d,-1,sizeof(d));
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j][i][j]=(a[i][j]=='#');
	cout<<dp(1,1,n,n)<<endl;
	return 0;
}