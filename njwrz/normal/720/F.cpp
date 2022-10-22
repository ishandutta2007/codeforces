#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n,k;
int a[100005],p[100005];
int it[100005];
int num[100005];
struct bit{
	int s[100005],len;
	void update(int x,int y){
		assert(x!=0);
		while(x<=len){
			s[x]+=y;
			x+=x&-x;
		}
	}
	int get(int x){
		int re=0;
		while(x){
			re+=s[x];
			x-=x&-x;
		}
		RE re;
	}
	void init(int l){
		FILL(s,0);len=l;
	}
}T1,T2;
struct bit2{
	int s[100005],len;
	void update(int x,int y){
		assert(x!=0);
		while(x<=len){
			gmin(s[x],y);
			x+=x&-x;
		}
	}
	int get(int x){
		int re=n+1;
		while(x){
			gmin(re,s[x]);
			x-=x&-x;
		}
		RE re;
	}
	void init(int l){
		FOR(i,1,l)s[i]=n+1;
		len=l;
	}
}T;
int sum[100005];
int pos[100005],cnt;
int nn;
P<int,int> check(int val){
	P<int,int> re=MP(0,0);
	FILL(sum,0);
	T1.init(n+1);T2.init(n+1);T.init(n+1);
	int it=lwb(num,num+nn+1,0)-num+1;
	T2.update(it,1);
	T.update(it,0);
	FOR(i,1,n){
		int it=upb(num,num+nn+1,p[i]-val)-num;
		int cnt=T2.get(it);
		re.S+=cnt*p[i]+T1.get(it);
		re.F+=cnt;
		int tl=T.get(it);
		if(tl<=i){
			sum[tl+1]++;sum[i+1]--;
		}
		it=lwb(num,num+nn+1,p[i])-num+1;
		T1.update(it,-p[i]);
		T2.update(it,1);
		T.update(it,i);
	}
	FOR(i,1,n)sum[i]+=sum[i-1];
	cnt=0;
	FOR(i,1,n)if(!sum[i])pos[++cnt]=i;
	if(!cnt)RE re;
	int maxi=-1e18,mini=1e18;
	rep(i,0,pos[1])gmin(mini,p[i]);
	FOR(i,pos[cnt],n)gmax(maxi,p[i]);
	re.F++;
	re.S+=maxi-mini;
	FOR(i,2,cnt){
		maxi=-1e18,mini=1e18;
		FOR(j,pos[i-1],pos[i]-1)gmin(mini,p[j]),gmax(maxi,p[j]);
		if(maxi-mini>=val)re.S+=maxi-mini,re.F++;
	}
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	FOR(i,1,n)cin>>a[i],p[i]=p[i-1]+a[i],num[i]=p[i];
	sort(num,num+n+1);
	nn=unique(num,num+n+1)-num-1;
	int l=-1e10,r=1e10,ans=0;
	while(r>=l){
		int mid=(l+r)>>1;
		if(check(mid).F>=k){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	P<int,int> now=check(ans);
	cout<<now.S-now.F*ans+k*ans;
	RE 0;
}