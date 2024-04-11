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

int n,m;
int val[505],p[505];
bool vis[505];

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++){
		putchar('?'),putchar(' ');
		for(int j=1;j<=m;j++) putchar('0'+(j==i));
		putchar('\n');
		fflush(stdout);
		val[i]=readint();
	}
	for(int i=1;i<=m;i++) p[i]=i;
	sort(p+1,p+m+1,[&](int x,int y){return val[x]<val[y];});
	int now=0;
	for(int i=1;i<=m;i++){
		vis[p[i]]=1;
		putchar('?'),putchar(' ');
		for(int j=1;j<=m;j++) putchar('0'+vis[j]);
		putchar('\n');
		fflush(stdout);
		int tmp=readint();
		if(tmp-now==val[p[i]]) now+=val[p[i]];
		else vis[p[i]]=0;
	}
	printf("! %d\n",now);
	return 0;
}