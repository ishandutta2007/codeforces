// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,x;
int a[50005],d[50005][2][2];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		x=readint();
		if(n==1){
			printf("1\n");
			continue;
		}
		d[2][0][0]=0;
		d[2][0][1]=1;
		d[2][1][0]=1;
		if(a[1]+a[2]>=x*2) d[2][1][1]=2;
		else d[2][1][1]=-(1<<30);
		for(int i=3;i<=n;i++){
			d[i][0][0]=max(d[i-1][0][0],d[i-1][0][1]);
			d[i][0][1]=max(d[i-1][1][0],d[i-1][1][1]);
			d[i][1][0]=max(d[i-1][0][0],d[i-1][0][1])+1;
			if(a[i]+a[i-1]>=x*2){
				d[i][1][1]=d[i-1][1][0]+1;
				if(a[i]+a[i-1]+a[i-2]>=x*3) chkmax(d[i][1][1],d[i-1][1][1]+1);
			}
			else d[i][1][1]=-(1<<30);
		}
		printf("%d\n",max(max(d[n][0][0],d[n][0][1]),max(d[n][1][0],d[n][1][1])));
	}
	return 0;
}