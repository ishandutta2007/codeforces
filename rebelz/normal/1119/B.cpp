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
ll ans;
int a[1005],b[1005];

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=n;i>=1;i--){
		ans=0;
		for(int j=1;j<=i;j++) b[j]=a[j];
		sort(b+1,b+i+1);
		for(int j=i;j>=2;j-=2) ans+=max(b[j],b[j-1]);
		if(i&1) ans+=b[1];
		if(ans<=m) return printf("%d\n",i),0;
	}
	return 0;
}