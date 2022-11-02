#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
//#define int long long
using namespace std;
typedef long long ll;
int read(){
	char c=getchar();int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=51;
const int M=20;
int n,m,cnt[1<<M],ycl[1<<M];
ll s[N][N+5],g[1<<M],f[1<<M];
double d[1<<M];
char a[51][51];
int tran(char x){
	if(x>='A' && x<='Z')return x-'A';
	else return x-'a'+26;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
	}
	m=strlen(a[n]+1);
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++){
			s[k][tran(a[i][k])]|=(1ll<<(i-1ll));
		}
	}
	for(int k=1;k<=n;k++){
		memset(f,0,sizeof(f));
		f[0]=(1ll<<n)-1ll;
		if(__builtin_popcount(f[0])>1)g[0]++;
		for(int i=1;i<(1<<m);i++){
			ll tmp=(i&(-i));
			ll j=__builtin_ffs(tmp);
			f[i]=(f[i^tmp]&s[j][tran(a[k][j])]);
			if(__builtin_popcountll(f[i])>1)g[i]++;
		}
	}
	for(int i=(1<<m)-2;i>=0;i--){
		int tmp=__builtin_popcount(i);
		tmp=m-tmp;
		double tt=1.0/tmp;
		for(int k=1;k<=m;k++){
			if(!(i&(1<<k-1))){
				d[i]=d[i]+d[i|(1<<k-1)];
			}
		}
		d[i]=d[i]*tt+1.0*g[i]/n;
	}
	printf("%.10lf",d[0]);
	return 0;
}