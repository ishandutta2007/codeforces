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
int a[1005][1005],ans[1005][1005];
char s[100005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=readint();
		scanf("%s",s+1);
		int A=0,B=0,C=0,t1=1,t2=2,t3=3;
		for(int i=1;i<=m;i++){
			if(s[i]=='R') B++;
			if(s[i]=='L') B--;
			if(s[i]=='D') A++;
			if(s[i]=='U') A--;
			if(s[i]=='I') swap(B,C),swap(t2,t3);
			if(s[i]=='C') swap(A,C),swap(t1,t3);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int na,nb,nc;
				na=t1==1?i:t1==2?j:a[i][j];
				nb=t2==1?i:t2==2?j:a[i][j];
				nc=t3==1?i:t3==2?j:a[i][j];
				na=((na+A)%n+n-1)%n+1;
				nb=((nb+B)%n+n-1)%n+1;
				nc=((nc+C)%n+n-1)%n+1;
				ans[na][nb]=nc;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) printf("%d ",ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}