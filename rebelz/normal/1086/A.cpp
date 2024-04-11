#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int a,b;
	bool operator<(const node c)const{
		if(a==c.a) return b<c.b;
		return a<c.a;
	}
}k[5];

int tot;
bool flag[1005][1005];
int ansx[1000005],ansy[1000005];

int main(){
	for(int i=1;i<=3;i++) k[i].a=readint(),k[i].b=readint();
	sort(k+1,k+4);
	for(int i=k[1].a;i<=k[2].a;i++) flag[i][k[1].b]=true;
	for(int i=min(k[1].b,k[2].b);i<=max(k[1].b,k[2].b);i++) flag[k[2].a][i]=true;
	if((k[1].b<=k[2].b&&k[2].b<=k[3].b)||(k[1].b>k[2].b&&k[3].b<=k[2].b)){
		for(int i=k[2].a;i<=k[3].a;i++) flag[i][k[2].b]=true;
		for(int i=min(k[3].b,k[2].b);i<=max(k[2].b,k[3].b);i++) flag[k[3].a][i]=true;
	}
	else if((k[1].b<=k[2].b&&k[3].b<=k[1].b)||(k[2].b<=k[3].b&&k[3].b>=k[1].b)){//k2.a k1.b
		for(int i=k[2].a;i<=k[3].a;i++) flag[i][k[1].b]=true;
		for(int i=min(k[3].b,k[1].b);i<=max(k[3].b,k[1].b);i++) flag[k[3].a][i]=true;
	}
	else for(int i=k[2].a;i<=k[3].a;i++) flag[i][k[3].b]=true;
	for(int i=0;i<=1000;i++) for(int j=0;j<=1000;j++) if(flag[i][j]) ansx[++tot]=i,ansy[tot]=j;
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++) printf("%d %d\n",ansx[i],ansy[i]);
	return 0;
}