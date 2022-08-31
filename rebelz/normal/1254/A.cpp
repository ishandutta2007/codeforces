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

int n,m,k;
char s[105][105];
int ans[105][105];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint(); k=readint();
		for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
		int cnt=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i][j]=='R') cnt++;
		int nx=1,ny=1,now=1;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans[i][j]=0;
		for(int i=1;i<=k;i++){
			int tmp=cnt/(k-i+1);
			while(tmp){
				ans[nx][ny]=i;
				if(s[nx][ny]=='R') tmp--,cnt--;
				ny+=now;
				if(ny<1||ny>m) nx++,ny-=now,now*=-1;
			}
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(!ans[i][j]) ans[i][j]=k;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(ans[i][j]<=26) printf("%c",ans[i][j]+'a'-1);
				else if(ans[i][j]<=52) printf("%c",ans[i][j]-26+'A'-1);
				else printf("%c",ans[i][j]-52+'0'-1);
			}
			printf("\n");
		}
	}
	return 0;
}