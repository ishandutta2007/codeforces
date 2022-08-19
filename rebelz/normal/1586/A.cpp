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

int n,tot;
bool fl[20005];
int prm[20005],a[205];

void getprime(int m){
	fl[1]=1;
	for(int i=2;i<=m;i++){
		if(!fl[i]) prm[++tot]=i;
		for(int j=1;j<=tot&&i*prm[j]<=m;j++){
			fl[i*prm[j]]=1;
			if(i%prm[j]==0) break;
		}
	}
}

int main(){
	getprime(20000);
	int T=readint();
	while(T--){
		n=readint();
		int sum=0;
		for(int i=1;i<=n;i++) a[i]=readint(),sum+=a[i];
		if(fl[sum]){
			printf("%d\n",n);
			for(int i=1;i<=n;i++) printf("%d ",i);
			printf("\n");
		}
		else{
			for(int i=1;i<=n;i++){
				if(fl[sum-a[i]]){
					printf("%d\n",n-1);
					for(int j=1;j<=n;j++) if(i!=j) printf("%d ",j);
					printf("\n");
					break;
				}
			}
		}
	}
	return 0;
}