#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int M=2e4+5;
const int K=20;
const int B=72;

bool vis[M];
int pr[M],cntp=0;
void ysgs(int m) {
	for (int i=2;i<=m;i++) {
		if (vis[i]) {
			continue;
		}
		pr[cntp++]=i;
		for (int j=i+i;j<=m;j+=i) {
			vis[j]=1;
		}
	}
}
int n,m,C,Q,a[N],sum[K][N];
vector<pair<int,int>>b[N],big[N];
vector<pair<int,int>>split(int x) {
	vector<pair<int,int>>ret;
	for (int i=0;pr[i]*pr[i]<=x;i++) {
		if (x%pr[i]==0) {
			int cnt=0;
			while (x%pr[i]==0) {
				x/=pr[i],cnt++;
			}
			ret.emplace_back(pr[i],cnt);
		}
	}
	if (x>1) {
		ret.emplace_back(x,1);
	}
	return ret;
}
const int SIZ=1e5/73+1;
int f[1<<K],pre[SIZ];
bitset<SIZ>is[1<<K];
int tim[N],p[N],cnt;
void add(const vector<pair<int,int>>&x,int y) {
	for (auto [a,b]:x) {
		tim[a]+=b*y;
	}
}
struct Query {
	int l,r,id;
	bool operator <(const Query &a) {
		return l/B!=a.l/B?l<a.l:(((l/B)&1)?r>a.r:r<a.r);
	}
}q[N];
int ans[N];
int calc(int p) {
	return pre[C/p];
}
int query(int l,int r) {
	int S=0;
	for (int i=0;i<K;i++) {
		if (sum[i][r]-sum[i][l-1]) {
			S|=1<<i;
		}
	}
	int ret=f[S];
	for (int i=1;i<SIZ;i++) {
		pre[i]=pre[i-1]+!is[S][i];
	}
	cnt=0;
	for (int i=K;i<cntp;i++) {
		if (tim[pr[i]]) {
			p[cnt++]=pr[i];
		}
	}
	for (int i=0;i<cnt;i++) {
		ret-=calc(p[i]);
		for (int j=i+1;j<cnt&&1LL*p[i]*p[j]<=C;j++) {
			ret+=calc(p[i]*p[j]);
		}
	}
	return ret;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ysgs(2e4);
	cin>>n>>m>>C>>Q;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		b[i]=split(a[i]);
		for (int j=0;j<K;j++) {
			sum[j][i]=sum[j][i-1]+(a[i]%pr[j]==0);
		}
		for (auto [x,y]:b[i]) {
			if (x>B) {
				big[i].emplace_back(x,y);
			}
		}
	}
	for (int S=0;S<(1<<K);S++) {
		int tmp=C,q=1;
		for (int i=0;i<K;i++) {
			if (S>>i&1) {
				tmp/=pr[i],q*=-1;
			}
		}
		f[S]=tmp*q;
	}
	for (int i=0;i<K;i++) {
		for (int S=0;S<(1<<K);S++) {
			if (S>>i&1) {
				f[S]+=f[S^(1<<i)];
			}
		}
	}
	for (int i=0;i<K;i++) {
		for (int j=pr[i];j<=SIZ;j+=pr[i]) {
			is[1<<i][j]=1;
		}
	}
	for (int S=1;S<(1<<K);S++) {
		for (int i=0;i<K;i++) {
			if (S>>i&1) {
				is[S]=is[1<<i]|is[S^(1<<i)];
				break;
			}
		}
	}
	for (int i=1;i<=Q;i++) {
		cin>>q[i].l>>q[i].r;
		q[i].id=i;
	}
	sort(q+1,q+1+Q);
	for (int i=1,l=1,r=0;i<=Q;i++) {
		while (r<q[i].r) {
			add(big[++r],1);
		}
		while (l>q[i].l) {
			add(big[--l],1);
		}
		while (r>q[i].r) {
			add(big[r--],-1);
		}
		while (l<q[i].l) {
			add(big[l++],-1);
		}
		ans[q[i].id]=query(q[i].l,q[i].r);
	}
	for (int i=1;i<=Q;i++) {
		cout<<ans[i]<<"\n";
	}
	
	return 0;
}