#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll ans;
int n,k;
int a[200005],b[200005],lst[200005];
map<int,int> mp;

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++){
		b[i]=a[i];
		for(int j=0;j<k;j++) b[i]^=(1<<j);
	}
	int s=0,g; mp[0]=1;
	for(int i=1;i<=n;i++){
		if((s^a[i])&1) a[i]=b[i];
		s^=a[i];
		mp[s]++;
	}
	ans=1ll*n*(n+1)/2;
	for(auto x:mp){
		g=x.second;
		ans-=1ll*(g/2)*(g/2-1)/2+1ll*(g-g/2)*(g-g/2-1)/2;
	}
	printf("%lld\n",ans);
	return 0;
}