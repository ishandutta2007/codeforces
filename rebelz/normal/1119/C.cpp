#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
int a[505][505],b[505][505],ax[505],ay[505],bx[505],by[505];

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=readint();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ax[i]^=a[i][j];
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) ay[i]^=a[j][i];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) b[i][j]=readint();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) bx[i]^=b[i][j];
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) by[i]^=b[j][i];
	bool fl=false;
	for(int i=1;i<=n;i++) if(ax[i]!=bx[i]) fl=true;
	for(int i=1;i<=m;i++) if(ay[i]!=by[i]) fl=true;
	if(fl) printf("No\n");
	else printf("Yes\n");
	return 0;
}