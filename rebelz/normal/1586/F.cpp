#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k,m;
ll pw[1005];

int main(){
	n=readint(); k=readint();
	pw[0]=1;
	for(int i=1;pw[i-1]<n;i++) pw[i]=pw[i-1]*k;
	while(pw[m]<n) m++;
	m--;
	printf("%d\n",m+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int l=m;l>=0;l--){
				if((i-1)/pw[l]!=(j-1)/pw[l]){
					printf("%d ",l+1);
					break;
				}
			}
		}
	}
	return 0;
}