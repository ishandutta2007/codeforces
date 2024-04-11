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

int n,tot;
int prm[100005];
bool fl[100005];

void getprime(int N){
	fl[1]=1;
	for(int i=2;i<=N;i++){
		if(!fl[i]) prm[++tot]=i;
		for(int j=1;j<=tot&&i*prm[j]<=N;j++){
			fl[i*prm[j]]=1;
			if(i%prm[j]==0) break;
		}
	}
}

int main(){
	n=readint();
	if(n<=2){
		printf("1\n");
		for(int i=1;i<=n;i++) printf("1 ");
		printf("\n");
	}
	else{
		printf("2\n");
		getprime(n+1);
		for(int i=2;i<=n+1;i++){
			if(!fl[i]) printf("1 ");
			else printf("2 ");
		}
		printf("\n");
	}
	return 0;
}