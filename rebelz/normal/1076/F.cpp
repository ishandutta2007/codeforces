#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k;
int x[300005],y[300005],dx[300005],dy[300005];

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) x[i]=readint();
	for(int i=1;i<=n;i++) y[i]=readint();
	int tx,ty;
	for(int i=1;i<=n;i++){
		tx=(x[i]+y[i]+dy[i-1])/(k+1);
		if(tx>x[i]) return printf("NO\n"),0;
		if(tx==x[i]) dy[i]=x[i]+y[i]+dy[i-1]-tx*(k+1);
		else dy[i]=0;
		ty=(x[i]+y[i]+dx[i-1])/(k+1);
		if(ty>y[i]) return printf("NO\n"),0;
		if(ty==y[i]) dx[i]=x[i]+y[i]+dx[i-1]-ty*(k+1);
		else dx[i]=0;
//		cout<<tx<<' '<<ty<<' '<<dx[i]<<' '<<dy[i]<<endl;
	}
	printf("YES\n");
	return 0;
}