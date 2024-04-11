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

int n,m,q;
int a[200005],b[200005],lst[200005],pos[200005],f[200005][20],r[200005];

int main(){
	n=readint(); m=readint(); q=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) lst[a[i%n+1]]=a[i];
	for(int i=1;i<=m;i++) b[i]=readint();
	for(int i=1;i<=m;i++){
		f[i][0]=pos[lst[b[i]]];
		pos[b[i]]=i;
	}
	for(int i=1;i<=18;i++) for(int j=1;j<=m;j++) f[j][i]=f[f[j][i-1]][i-1];
	for(int i=1;i<=m;i++){
		int tmp=i;
		for(int j=0;j<=18;j++) if((n-1)&(1<<j)) tmp=f[tmp][j];
		r[i]=max(r[i-1],tmp);
	}
	while(q--){
		int x=readint(),y=readint();
		if(r[y]>=x) printf("1");
		else printf("0");
	}
	return 0;
}