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

int n;
char s[305][305];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
		int a[3],b[3];
		for(int i=0;i<3;i++) a[i]=b[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(s[i][j]=='O') a[(i+j)%3]++;
				else if(s[i][j]=='X') b[(i+j)%3]++;
			}
		}
		int mina=1<<30; pii opt;
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(i!=j&&chkmin(mina,a[i]+b[j])) opt=mp(i,j);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(s[i][j]=='O'&&(i+j)%3==opt.fi) printf("X");
				else if(s[i][j]=='O') printf("O");
				else if(s[i][j]=='X'&&(i+j)%3==opt.se) printf("O");
				else if(s[i][j]=='X') printf("X");
				else printf(".");
			}
			printf("\n");
		}
	}
	return 0;
}