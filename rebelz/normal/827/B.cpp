#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot,x,y,k,now;

int main(){
	tot=1;
	n=readint(); k=readint();
	x=(n-1)/k; y=n-1-x*k;
//	cout<<x<<' '<<y<<endl;
	if(y>1) printf("%d\n",(x+1)*2);
	else if(y==1) printf("%d\n",2*x+1);
	else printf("%d\n",x*2);
	for(int i=1;i<=y;i++){
		now=1;
		for(int j=1;j<=x+1;j++){
			printf("%d %d\n",now,++tot);
			now=tot;
		}
	}
	for(int i=1;i<=k-y;i++){
		now=1;
		for(int j=1;j<=x;j++){
			printf("%d %d\n",now,++tot);
			now=tot;
		}
	}
	return 0;
}