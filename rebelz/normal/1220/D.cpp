#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

bool chkmin(int &x,int y){return x>y?x=y,1:0;}
bool chkmax(int &x,int y){return x<y?x=y,1:0;}

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
ll a[200005],num[200005],cnt[200005];
vector<ll> ans;

int main(){
	n=readint();
	for(int i=1;i<=n;i++){
		a[i]=readint();
		ll tmp=a[i];
		while(!(tmp&1)) tmp>>=1,num[i]++;
		cnt[num[i]]++;
	}
	int now=0,opt=0;
	for(int i=0;i<=70;i++) if(chkmax(now,cnt[i])) opt=i;
	for(int i=1;i<=n;i++) if(num[i]!=opt) ans.push_back(a[i]);
	printf("%d\n",ans.size());
	for(auto x:ans) printf("%lld ",x);
	printf("\n");
	return 0;
}