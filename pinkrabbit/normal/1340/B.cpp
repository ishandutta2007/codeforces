#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 2015
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,k;
const char t[10][8]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
char s[MN][8];
int Dif[MN][10],f[MN][MN];
int main(){
	scanf("%d%d",&n,&k);
	F(i,1,n)scanf("%s",s[i]);
	f[n+1][0]=1;
	dF(i,n,1){
		int dif[10];
		F(o,0,9){
			dif[o]=0;
			int ok=1;
			F2(j,0,7){
				if(s[i][j]=='1'&&t[o][j]=='0')ok=0;
				else if(s[i][j]=='0'&&t[o][j]=='1')++dif[o];
			}
			if(!ok)dif[o]=-1;
			Dif[i][o]=dif[o];
		}
		F(j,0,k){
			F(o,0,9)if(dif[o]!=-1)
				if(j>=dif[o])f[i][j]|=f[i+1][j-dif[o]];
		}
	}
	if(!f[1][k])return puts("-1"),0;
	int now=k;
	F(i,1,n){
		int x=-1;
		dF(o,9,0)if(Dif[i][o]!=-1&&now>=Dif[i][o]&&f[i+1][now-Dif[i][o]]){x=o;break;}
		printf("%d",x);
		now-=Dif[i][x];
	}puts("");
	return 0;
}