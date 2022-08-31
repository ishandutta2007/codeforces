#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[1000005];
ll d[1000005][5];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	memset(d,-0x3f,sizeof(d));
	d[0][0]=0;
	for(int i=1;i<=n;i++){
		d[i][0]=max(d[i-1][0],max(d[i-1][2]+a[i],d[i-1][1]-a[i]));
		d[i][1]=max(d[i-1][1],d[i-1][0]+a[i]);
		d[i][2]=max(d[i-1][2],d[i-1][0]-a[i]);
	}
	cout<<d[n][0]<<endl;
	return 0;
}