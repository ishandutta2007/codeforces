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

const int cys=1000000007;
int n;
int a[1000005],nxt[1000005],pl[1000005];
ll d[1000005];
vector<int> vec[1000005];
char s[1000005];

ll mod(ll x){return x>=cys?x-cys:x;}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='1') a[i]=0;
		else a[i]=a[i-1]+1;
	}
	for(int i=1;i<=n;i++) vec[a[i]].pb(i);
	int now=n+1,lst=0;
	for(int i=n;i>=0;i--){
		nxt[i]=now;
		if(s[i]=='1') now=i,chkmax(lst,i);
	}
	if(now==n+1) return printf("%d\n",n),0;
	d[0]=1;
	ll ans=0;
	for(int i=0;i<n;i++){
		if(i) pl[a[i]]++;
		if(s[i+1]=='1'){
			d[i+1]=mod(d[i+1]+d[i]);
			if(pl[a[i]+1]<vec[a[i]+1].size()&&i>=now){
				d[vec[a[i]+1][pl[a[i]+1]]]=mod(d[vec[a[i]+1][pl[a[i]+1]]]+d[i]);
			}
		}
		else{
			d[i+1]=mod(d[i+1]+d[i]);
			if(nxt[i]<=n) d[nxt[i]]=mod(d[nxt[i]]+d[i]);
		}
		if(a[i]<=a[n]&&i>=now) ans=mod(ans+d[i]);
	}
	printf("%lld\n",mod(ans+d[n]));
	return 0;
}