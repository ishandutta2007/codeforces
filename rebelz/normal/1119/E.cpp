#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,ans;
ll a[300005],d[300005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++){
		if(a[i]>=d[i-1]*2) a[i]-=d[i-1]*2,ans+=d[i-1],d[i]=0;
		else ans+=a[i]/2,d[i]=d[i-1]-a[i]/2,a[i]-=a[i]/2*2;
		ans+=a[i]/3;
		a[i]%=3;
		d[i]+=a[i];
	}
	cout<<ans<<endl;
	return 0;
}