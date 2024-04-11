#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n,ans;
int c[105][105],a[105],d[105][10005];

int mod(int x){return x>=cys?x-cys:x;}

int main(){
	for(int i=0;i<=100;i++) c[i][0]=1;
	for(int i=1;i<=100;i++) for(int j=1;j<=100;j++) c[i][j]=mod(c[i-1][j-1]+c[i-1][j]);
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	d[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=i;j>=1;j--)
			for(int k=0;k<=j*100;k++)
				if(k>=a[i]) d[j][k]=mod(d[j][k]+d[j-1][k-a[i]]);
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=24;j++) cout<<d[i][j]<<' ';
//		cout<<endl;
//	}
	sort(a+1,a+n+1);
	bool flag=true;
	for(int i=1;i<=n;i++) if(a[i]!=a[1]&&a[i]!=a[n]) flag=false;
	if(flag) return printf("%d\n",n),0;
	int j;
	for(int i=1;i<=n;){
//		cout<<"TEST "<<i<<endl;
		for(j=i;a[j]==a[i];j++); j--;
//		cout<<j<<endl;
		for(int k=1;k<=j-i+1;k++) if(d[k][k*a[i]]==c[j-i+1][k]) ans=max(ans,k);
		i=j+1;
	}
	printf("%d\n",ans);
	return 0;
}