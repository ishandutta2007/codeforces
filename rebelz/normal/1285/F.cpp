#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,tot,top;
int a[100005],prm[100005],cnt[100005],s[100005],mu[100005];
bool fl[100005];
vector<int> dv[100005],vec[100005];

void getprime(){
	fl[1]=mu[1]=1;
	for(int i=2;i<=m;i++){
		if(!fl[i]) prm[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot&&i*prm[j]<=m;j++){
			fl[i*prm[j]]=1;
			if(i%prm[j]==0){
				mu[i*prm[j]]=0;
				break;
			}
			mu[i*prm[j]]=-mu[i];
		}
	}
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),chkmax(m,a[i]);
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	if(n==1) return printf("%d\n",a[1]),0;
	for(int i=1;i<=m;i++) for(int j=i;j<=m;j+=i) dv[j].pb(i);
	for(int i=1;i<=n;i++) for(auto r:dv[a[i]]) vec[r].pb(i);
	for(int i=1;i<=m;i++) reverse(vec[i].begin(),vec[i].end());
	getprime();
	ll ans=0;
	for(int i=1;i<=m;i++){
		top=0;
		for(auto r:vec[i]){
			int sum=0;
			for(auto k:dv[a[r]/i]) sum+=mu[k]*cnt[k];
			while(sum){
				if(__gcd(s[top],a[r]/i)==1) chkmax(ans,1ll*s[top]*a[r]),sum--;
				for(auto k:dv[s[top]]) cnt[k]--;
				top--;
			}
			for(auto k:dv[a[r]/i]) cnt[k]++;
			s[++top]=a[r]/i;
		}
		while(top){
			for(auto k:dv[s[top]]) cnt[k]--;
			top--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}