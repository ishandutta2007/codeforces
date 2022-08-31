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

int n,s;
int a[200005],f[200005],to[200005];
pii b[200005];
bool vis[200005];
vector<vector<int> > ans;

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

int main(){
	n=readint(); s=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),b[i]=mp(a[i],i);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++) to[b[i].se]=i;
//	for(int i=1;i<=n;i++) cout<<to[i]<<' ';
//	cout<<endl;
	for(int i=1;i<=n;i++)
		while(i!=to[i]&&a[to[i]]==b[to[i]].fi)
			swap(b[to[i]].se,b[to[to[i]]].se),swap(to[to[i]],to[i]);
	for(int i=1;i<=n;i++) f[i]=i;
	int all=n,cnt=0;
	for(int i=1;i<=n;i++){
		if(i==to[i]) all--;
		if(vis[i]||i==to[i]) continue;
		vis[i]=1;
		cnt++;
		for(int j=to[i];j!=i;j=to[j]) vis[j]=1,f[j]=i;
	}
//	for(int i=1;i<=n;i++) cout<<to[i]<<' ';
//	cout<<endl;
	int lst=0;
	for(int i=1;i<=n;i++){
		if(b[i].se==i) continue;
		if(!lst||b[i].fi!=b[lst].fi){
			lst=i;
			continue;
		}
		if(getf(b[lst].se)!=getf(b[i].se)){
			f[f[b[i].se]]=f[b[lst].se];
			swap(to[b[i].se],to[b[lst].se]);
			swap(b[i].se,b[lst].se);
			cnt--;
		}
	}
//	for(int i=1;i<=n;i++) cout<<to[i]<<' ';
//	cout<<endl;
	if(all>s) return printf("-1\n"),0;
	int tmp=s-all,num=0;
	vector<int> now(0),rem(0);
	for(int i=1;i<=n;i++){
		if(i==to[i]) continue;
		if(i!=f[i]) continue;
		now.pb(i);
		for(int j=to[i];j!=i;j=to[j]) now.pb(j);
		rem.pb(i);
		num++;
		if(num>=tmp){
			ans.pb(now);
			reverse(rem.begin(),rem.end());
			if(rem.size()>1) ans.pb(rem);
			now.clear(),rem.clear();
		}
	}
	if(now.size()) ans.pb(now);
	reverse(rem.begin(),rem.end());
	if(rem.size()>1) ans.pb(rem);
	printf("%d\n",ans.size());
	for(auto v:ans){
		printf("%d\n",v.size());
		for(auto x:v) printf("%d ",x);
		printf("\n");
	}
	return 0;
}