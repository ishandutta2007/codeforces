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

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	ll opt,pl,val;
	bool operator<(const node c)const{return val>c.val;}
}a[100005];

int n,m,k,cnt;
ll s[100005],maxa[100005],cho[100005];
pii p[100005];
vector<int> ans,ans1,ans2,ans3;
vector<pii> v[100005];
pair<double,int> mx[300000];

void build(int id,int l,int r){
	if(l==r){
		if(v[l].size()) mx[id]=mp(1.0*(s[l]+v[l][v[l].size()-1].fi)/s[l],l);
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	mx[id]=max(mx[id<<1],mx[id<<1|1]);
}

void change(int id,int l,int r,int x){
	if(l==r){
		if(!v[l].size()) return;
		ans.push_back(v[l][v[l].size()-1].se);
		s[l]+=v[l][v[l].size()-1].fi;
		v[l].pop_back();
		if(v[l].size()) mx[id]=mp(1.0*(s[l]+v[l][v[l].size()-1].fi)/s[l],l);
		else mx[id]=mp(0,l);
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid) change(id<<1,l,mid,x);
	else change(id<<1|1,mid+1,r,x);
	mx[id]=max(mx[id<<1],mx[id<<1|1]);
}

int main(){
	k=readint(); n=readint(); m=readint();
	for(int i=1;i<=k;i++) s[i]=readint();
	for(int i=1;i<=n;i++){
		a[i].opt=readint(),a[i].pl=readint(),a[i].val=readint();
		if(a[i].opt==2) v[a[i].pl].push_back(mp(a[i].val,i));
		if(a[i].opt==1&&chkmax(maxa[a[i].pl],a[i].val)) cho[a[i].pl]=i;
		if(a[i].opt==3) p[++cnt]=mp(a[i].val,i);
	}
	sort(p+1,p+cnt+1);
	for(int i=1;i<=k;i++) if(cho[i]&&a[cho[i]].val>s[i]) v[i].push_back(mp(a[cho[i]].val-s[i],cho[i]));
	for(int i=1;i<=k;i++) sort(v[i].begin(),v[i].end());
	build(1,1,k);
	for(int i=1;i<=m;i++){
		pair<double,int> tmp=mx[1];
		if(p[cnt].fi>tmp.fi) ans.push_back(p[cnt].se),cnt--;
		else change(1,1,k,tmp.se);
	}
	printf("%d\n",(int)ans.size());
	for(auto x:ans){
		if(a[x].opt==1) ans1.push_back(x);
		else if(a[x].opt==2) ans2.push_back(x);
		else ans3.push_back(x);
	}
	for(auto x:ans1) printf("%d ",x);
	for(auto x:ans2) printf("%d ",x);
	for(auto x:ans3) printf("%d ",x);
	printf("\n");
	return 0;
}