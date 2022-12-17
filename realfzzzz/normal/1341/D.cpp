#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
inline int readint2(){
	int x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)){
		x=x<<1|(c-'0');
		c=getchar();
	}
	return x;
}
const int maxn=2000+5;
int n,k,s[maxn];
const int s2[]={0B1110111,0B0010010,0B1011101,0B1011011,0B0111010,0B1101011,0B1101111,0B1010010,0B1111111,0B1111011};
int bitcnt[150];
bool dp[maxn][maxn];
int c[maxn][maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	k=readint();
	for(int i=0;i<n;i++) s[i]=readint2();
	for(int i=1;i<128;i++) bitcnt[i]=bitcnt[i^(i&-i)]+1;
	dp[n][0]=1;
	for(int i=n-1;i>=0;i--) for(int j=0;j<=k;j++) for(int h=0;h<10;h++)
		if(((~s[i]&127)|s2[h])==127&&bitcnt[s2[h]]-bitcnt[s[i]]<=j&&dp[i+1][j-bitcnt[s2[h]]+bitcnt[s[i]]]){
			dp[i][j]=1;
			c[i][j]=h;
		}
	if(!dp[0][k]){
		printf("-1\n");
		return 0;
	}
	int u=k;
	for(int i=0;i<n;i++){
		printf("%d",c[i][u]);
		u-=bitcnt[s2[c[i][u]]]-bitcnt[s[i]];
	}
	printf("\n");
	return 0;
}