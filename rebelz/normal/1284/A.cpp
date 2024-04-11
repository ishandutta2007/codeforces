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

int n,m,q;
int la[25],lb[25];
char a[25][15],b[25][15];

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1),la[i]=strlen(a[i]+1);
	for(int i=1;i<=m;i++) scanf("%s",b[i]+1),lb[i]=strlen(b[i]+1);
	q=readint();
	int x;
	while(q--){
		x=readint();
		for(int i=1;i<=la[(x-1)%n+1];i++) printf("%c",a[(x-1)%n+1][i]);
		for(int i=1;i<=lb[(x-1)%m+1];i++) printf("%c",b[(x-1)%m+1][i]);
		printf("\n");
	}
	return 0;
}