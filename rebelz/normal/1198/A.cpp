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

ll n,kk,tot;
ll a[400005],p[400005],k[400005];

int main(){
	n=readint(); kk=readint()*8;
	for(int i=1;i<=n;i++) a[i]=readint();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) p[i]=a[i];
	tot=unique(p+1,p+n+1)-p-1;
	ll t=kk/n;
	ll len=0,tmp=tot-1;
	while(tmp) tmp>>=1,len++;
	if(len<=t) return printf("0\n"),0;
	t=1ll<<t;
	int cnt=0,now=0; a[0]=a[1];
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]) cnt++;
		else{
			now++;
			k[now]=i-1;
			cnt=1;
		}
	}
	now++;
	k[now]=n;
	a[n+1]=a[n];
	cnt=0;
	ll ans=1ll<<60,kt=0;
	for(int i=n;i>=1;i--){
		if(a[i]==a[i+1]) cnt++;
		else{
			kt++;
			if(tot-t-kt<0) break;
			ans=min(ans,k[tot-t-kt]+(n-i));
		}
	}
	cout<<ans<<endl;
	return 0;
}