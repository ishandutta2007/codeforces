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

const int cys=1000000007;
int n;
ll d[405][405];

ll mod(ll x){return x>=cys?x-cys:x;}

int main(){
	n=readint();
	d[1][0]=d[1][1]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=n+1;j++){
			for(int k=0;k<=n+1;k++){
				ll tmp=d[i-1][j]*d[i-1][k]%cys;
				if(j+k<=n) d[i][j+k]+=tmp;
				if(j+k+1<=n) d[i][j+k+1]+=tmp;
				if(j+k<=n) d[i][j+k]+=tmp*2*(j+k);
				if(j+k-1<=n&&j+k-1>=0) d[i][j+k-1]+=1ll*(j+k)*(j+k-1)*tmp;
			}
		}
		for(int j=0;j<=n+1;j++) d[i][j]%=cys;
	}
	cout<<d[n][1]<<endl;
	return 0;
}