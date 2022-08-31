#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k;

int main(){
	n=readint(); m=readint(); k=readint()+1;
	ld x=m,y=n+k,ans=1,ret=1;
	for(int i=1;i<=k;i++){
		ret*=x/y;
		x--,y--;
	}
	if(ans-ret<0) return printf("0\n"),0;
	else printf("%.10Lf\n",ans-ret);
	return 0;
}