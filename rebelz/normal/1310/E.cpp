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

const int cys=998244353;
int n,k;

ll mod(ll x){return x>=cys?x-cys:x;}

namespace task1{
	ll d[2025][2025];
	void work(){
		d[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++){
				d[i][j]=d[i-1][j];
				if(j>=i) d[i][j]=mod(d[i][j]+d[i][j-i]);
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++) ans=mod(ans+d[n][i]);
		printf("%lld\n",ans);
	}
}

namespace task2{
	ll d[2025][2025],f[2025][2025];
	void work(){
		d[0][0]=1;
		for(int i=n;i>=1;i--)
			for(int j=0;j<=n/i;j++)
				for(int k=0;k<=n;k++)
					if(j&&k>=i*j) d[j][k]=mod(d[j][k]+d[j-1][k-i*j]);
		ll ans=0;
		for(int i=1;i<=n;i++) for(int j=0;j<=n;j++) ans=mod(ans+d[i][j]);
		printf("%lld\n",ans);
	}
}

namespace taskg3{
	vector<int> a;
	map<vector<int>,bool> bk;
	int ans;
	bool check(vector<int> x){
		vector<int> tmp(0);
		for(int i=0;i<x.size();i++) for(int j=0;j<x[i];j++) tmp.push_back(i+1);
		int sum=0;
		for(int i=0;i<tmp.size();i++) sum+=tmp[i]*(tmp.size()-i);
		return sum<=n;
	}
	vector<int> getans(vector<int> x){
		sort(x.begin(),x.end());
		int lst=0;
		vector<int> ret(0);
		for(int i=1;i<x.size();i++) if(x[i]!=x[i-1]) ret.push_back(i-lst),lst=i;
		ret.push_back(x.size()-lst);
		return ret;
	}
	bool dfs(int now,int sum){
		if(now>=1){
			if(!check(a)) return 0;
			vector<int> tmp=a;
			for(int i=1;i<=k-3;i++) tmp=getans(tmp);
			sort(tmp.begin(),tmp.end());
			if(!bk.count(tmp)) bk[tmp]=1,ans++;
		}
		int g=now?a[now-1]:64;
		for(int i=1;i<=g&&i<=64-sum;i++){
			a.push_back(i);
			if(!dfs(now+1,sum+i)){
				a.pop_back();
				break;
			}
			a.pop_back();
		}
		return 1;
	}
	void work(){
		ans=0;
		dfs(0,0);
		printf("%d\n",ans);
	}
}

int main(){
	n=readint(); k=readint();
	if(k>=20) printf("1\n");
	else if(k==1) task1::work();
	else if(k==2) task2::work();
	else taskg3::work();
	return 0;
}