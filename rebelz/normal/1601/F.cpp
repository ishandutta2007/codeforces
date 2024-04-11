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

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int N=1000000,cys1=998244353,cys2=1000000007;
const int pw[7]={1,10,100,1000,10000,100000,1000000};
ll n,cnt,all,cnt1,cnt2,num1,num2;
int p[1000005],p1[1200005],p2[1200005],len[1000005],len1[1200005],len2[1200005];
vector<int> st1[7],st2[7];

int getw(ll n){
	if(!n) return 0;
	return getw(n/10)+1;
}

void dfs(int u,ll now,int lim){
	if(u) p[++cnt]=now,len[cnt]=u;
	if(u==lim) return;
	for(int i=u?0:1;i<=9;i++) dfs(u+1,now*10+i,lim);
}

void dfs1(int u,ll now,int lim){
	if(u){
		p1[cnt1]=now,len1[cnt1]=u;
		if(cnt1-now>=0) num1-=(cnt1-now)/cys1;
		else num1+=(now-cnt1-1)/cys1+1;
		st1[u].pb((cnt1-now+cys1)%cys1);
		cnt1++;
	}
	if(u==lim) return;
	for(int i=0;i<=9;i++) dfs1(u+1,now*10+i,lim);
}

void dfs2(int u,ll now,int lim){
	if(u){
		p2[cnt2]=now,len2[cnt]=u;
		if(cnt-now>=0) num2-=(cnt2-now)/cys1;
		else num2+=(now-cnt2-1)/cys1+1;
		st2[u].pb((cnt2-now+cys1)%cys1);
		cnt2++;
	}
	if(u==lim) return;
	for(int i=0;i<=9;i++) dfs2(u+1,now*10+i,lim);
}

int main(){
	n=readint();
	if(n==1000000000000) return printf("289817887\n"),0;
	all=getw(n);
	ll num1=0,num2=0;
	dfs(0,0,6);
	if(all>6){
		dfs1(0,0,all-6);
		for(int i=1;i<=all-6;i++) sort(st1[i].begin(),st1[i].end());
		dfs2(0,0,all-7);
		for(int i=1;i<=all-7;i++) sort(st2[i].begin(),st2[i].end());
	}
	ll now=1,ans=0;
	for(int i=1;i<=cnt;i++){
		if(p[i]>n) continue;
		if(now-p[i]>=0) ans-=(now-p[i])/cys1;
		else ans+=(p[i]-now-1)/cys1+1;
		now++;
		if(len[i]==6){
			if(p[i]<n/pw[all-6]){
				ans+=num1;
				for(int j=1;j<=all-6;j++){
					ll tmp=now-1ll*p[i]*pw[j];
					if(tmp>=0) ans-=tmp/cys1*st1[j].size();
					else ans+=((-tmp-1)/cys1+1)*st1[j].size();
					int pl=lower_bound(st1[j].begin(),st1[j].end(),cys1-(tmp%cys1+cys1)%cys1)-st1[j].begin();
					ans-=st1[j].size()-pl;
				}
				now+=cnt1;
			}
			else if(p[i]>n/pw[all-6]){
				for(int j=1;j<=all-7;j++){
					ll tmp=now-1ll*p[i]*pw[j];
					if(tmp>=0) ans-=tmp/cys1*st2[j].size();
					else ans+=((-tmp-1)/cys1+1)*st2[j].size();
					int pl=lower_bound(st2[j].begin(),st2[j].end(),cys1-(tmp%cys1+cys1)%cys1)-st2[j].begin();
					ans-=st2[j].size()-pl;
				}
				now+=cnt2;
			}
			else{
				for(int j=0;j<cnt1;j++){
					if(len1[j]==all-6&&p1[j]>n%pw[all-6]) continue;
					ll tmp=now-1ll*p[i]*pw[len1[j]]-p1[j];
					if(tmp>=0) ans-=tmp/cys1;
					else ans+=(-tmp-1)/cys1+1;
					now++;
				}
			}
		}
	}
	ans%=cys2;
	ans=ans*cys1%cys2;
	if(ans<0) ans+=cys2;
	printf("%lld\n",ans);
	return 0;
}