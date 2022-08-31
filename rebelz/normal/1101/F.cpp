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
int a[405],d[405][405][405];

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) d[i][j][0]=a[j]-a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int l=i;
			for(int k=1;k<=n;k++){
				while(l<j&&max(d[i][l][k-1],a[j]-a[l])>max(d[i][l+1][k-1],a[j]-a[l+1])) l++;
				d[i][j][k]=max(d[i][l][k-1],a[j]-a[l]);
			}
		}
	}
	int s,t,c,r; ll ans=0;
	for(int i=1;i<=m;i++){
		s=readint(); t=readint(); c=readint(); r=readint();
		ans=max(ans,1ll*c*d[s][t][r]);
	}
	printf("%lld\n",ans);
	return 0;
}