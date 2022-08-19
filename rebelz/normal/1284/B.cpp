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
int cnt[1000015],mx[100005],mn[100005];
bool fl[100005];
vector<int> a[100005];

int main(){
	n=readint();
	int x;
	for(int i=1;i<=n;i++){
		x=readint();
		while(x--) a[i].push_back(readint());
		mn[i]=1<<30;
		for(auto x:a[i]){
			if(x>mn[i]) fl[i]=1;
			chkmin(mn[i],x);
		}
		if(!fl[i]) mx[i]=a[i][0];
	}
	for(int i=1;i<=n;i++){
		if(!fl[i]) cnt[mx[i]]++;
		else cnt[1000005]++;
	}
	for(int i=1000005;i>=0;i--) cnt[i]+=cnt[i+1];
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(!fl[i]) ans+=cnt[mn[i]+1];
		else ans+=n;
	}
	printf("%lld\n",ans);
	return 0;
}