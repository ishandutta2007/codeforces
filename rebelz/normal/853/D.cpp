#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
ll a[300005],s[300005],lst[300005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		lst[i]=lst[i-1];
		if(a[i]==1000) lst[i]=i;
	}
	ll ans=1ll<<60;
	for(int i=1;i<=n;i++){
		ll tmp=s[i],now=s[i]/10;
		chkmin(ans,tmp+max(0ll,s[n]-s[i]-now));
		if(a[i]==1000){
			for(int j=i-1;j>=1;j--){
				if(a[j]!=2000) break;
				tmp=s[j-1]+1000,now=(s[j-1]+1000)/10;
				if(s[j-1]/10>=2000ll*(i-j)) now-=2000ll*(i-j);
				else tmp+=2000ll*(i-j)-s[j-1]/10,now-=s[j-1]/10;
				chkmin(ans,tmp+max(0ll,s[n]-s[i]-now));
			}
		}
		else{
			int pl=lst[i];
			if(!pl) continue;
			tmp=s[i]-1000,now=(s[i]-1000)/10;
			if(s[pl-1]/10>=1000) now-=1000;
			else tmp+=1000-s[pl-1]/10,now-=s[pl-1]/10;
			chkmin(ans,tmp+max(0ll,s[n]-s[i]-now));
		}
	}
	printf("%lld\n",ans);
	return 0;
}