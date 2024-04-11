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
pll a[200005];
multiset<ll> s;

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i].fi=readint();
	for(int i=1;i<=n;i++) a[i].se=readint();
	sort(a+1,a+n+1);
	ll ans=0,sum=0;
	for(int i=1;i<=n;i++){
		if(a[i].fi==a[i-1].fi) s.insert(a[i].se),sum+=a[i].se;
		else{
			int cnt=0;
			if(s.size()){
				auto it=s.end();
				do{
					it--;
					sum-=*it;
					ans+=sum;
					cnt++;
					if(cnt==a[i].fi-a[i-1].fi) break;
				}while(it!=s.begin());
				s.erase(it,s.end());
			}
			s.insert(a[i].se),sum+=a[i].se;
		}
	}
	if(s.size()){
		auto it=s.end();
		do{
			it--;
			sum-=*it;
			ans+=sum;
		}while(it!=s.begin());
	}
	printf("%lld\n",ans);
	return 0;
}