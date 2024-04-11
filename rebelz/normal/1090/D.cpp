#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

map<ll,int> mp;
int n,m,ansx,ansy;
int x[100005],y[100005],ans1[100005],ans2[100005];

int main(){
	n=readint(); m=readint();
	if(1ll*n*(n-1)/2==m){printf("NO\n");return 0;}
	for(int i=1;i<=m;i++) x[i]=readint(),y[i]=readint();
	for(int i=1;i<=m;i++) if(x[i]>y[i]) swap(x[i],y[i]);
	for(int i=1;i<=m;i++) mp[1ll*(x[i]-1)*n+y[i]]=1;
	bool flag=true;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(mp[1ll*(i-1)*n+j]!=1){
				ansx=i,ansy=j,flag=false;
				break;
			}
		}
		if(!flag) break;
	}
	printf("YES\n");
	int now=1;
	for(int i=1;i<=n;i++)
		if(i!=ansx&&i!=ansy)
			ans1[i]=ans2[i]=now++;
	ans1[ansx]=ans2[ansx]=ans2[ansy]=n,ans1[ansy]=n-1;
	for(int i=1;i<=n;i++) printf("%d ",ans1[i]);
	printf("\n");
	for(int i=1;i<=n;i++) printf("%d ",ans2[i]);
	printf("\n");
	return 0;
}