#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
int cnt[1100000],b[1100000];
ll uk[1100000];
ld d[1100000];
char a[55][25];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	m=strlen(a[1]+1);
	for(int i=1;i<(1<<m);i++){
		int tmp=i&(-i);
		for(int j=1;j<=m;j++) if((i>>(j-1))&1) cnt[i]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ll now=0;
			for(int k=1;k<=m;k++) if(a[i][k]==a[j][k]) now|=1<<(k-1);
			uk[now]|=(1ll<<(i-1))|(1ll<<(j-1));
		}
	}
	for(int i=(1<<m)-1;i>=1;i--) for(int j=1;j<=m;j++) if((i>>(j-1))&1) uk[i^(1<<(j-1))]|=uk[i];
	for(int i=0;i<(1<<m);i++) for(int j=1;j<=n;j++) if(!((uk[i]>>(j-1))&1)) b[i]++;
	for(int i=(1<<m)-1;i>=0;i--){
		if(b[i]==n){
			d[i]=0;
			continue;
		}
		for(int j=1;j<=m;j++) if(!((i>>(j-1))&1)) d[i]+=((ld)(n-b[i|(1<<(j-1))])/(n-b[i]))/(m-cnt[i])*d[i|(1<<(j-1))];
		d[i]+=1;
	}
	printf("%.12Lf\n",d[0]);
	return 0;
}