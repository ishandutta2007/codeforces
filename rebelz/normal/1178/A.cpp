#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
ll sum=0,cnt;
ll a[105],b[105];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),sum+=a[i];
	b[++cnt]=1;
	ll now=a[1];
	for(int i=2;i<=n;i++) if(a[1]>=a[i]*2) b[++cnt]=i,now+=a[i];
	if(now>sum/2){
		cout<<cnt<<endl;
		for(int i=1;i<=cnt;i++) cout<<b[i]<<' ';
		cout<<endl;
	}
	else cout<<0<<endl;
	return 0;
}