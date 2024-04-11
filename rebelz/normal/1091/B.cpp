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
	int x,y;
	bool operator<(const node c)const{
		if(x==c.x) return y<c.y;
		return x<c.x;
	}
}k[1005],a[1005];

int n;

int main(){
	n=readint();
	for(int i=1;i<=n;i++) k[i].x=readint(),k[i].y=readint();
	for(int i=1;i<=n;i++) a[i].x=readint(),a[i].y=readint();
	sort(k+1,k+n+1); sort(a+1,a+n+1);
	printf("%d %d\n",k[1].x+a[n].x,k[1].y+a[n].y);
	return 0;
}