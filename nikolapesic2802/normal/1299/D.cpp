// Problem : D. Around the World
// Contest : Codeforces Round #618 (Div. 1)
// URL : https://codeforces.com/contest/1299/problem/D
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=1e5+5,W=32,L=17,mod=1e9+7,C=374;
int add(int a,int b){
	a+=b;
	if(a>=mod)
		a-=mod;
	return a;
}
int sub(int a,int b){
	a-=b;
	if(a<0)
		a+=mod;
	return a;
}
int mul(int a,int b){
	return (ll)a*b%mod;
}
int pwrmod(int x,int k){
	int ans=1;
	for(;k;k>>=1,x=mul(x,x))
		if(k&1)
			ans=mul(ans,x);
	return ans;
}
vector<int> par(N),one(N,-1),dep(N),done(N);
pair<int,int> up[N][L];
vector<vector<bool> > moze(N,vector<bool>(W));
vector<vector<pair<int,int> > > graf(N);
int find(int tr){return tr==par[tr]?tr:par[tr]=find(par[tr]);}
bool merge(int a,int b){
	a=find(a),b=find(b);
	if(a==b)
		return 0;
	par[a]=b;
	return 1;
}
void dfs(int tr,int par){
	for(auto p:graf[tr])
		if(p.f!=par)
			dep[p.f]=dep[tr]+1,up[p.f][0]={tr,p.s},dfs(p.f,tr);
}
int getXor(int a,int b){
	if(dep[a]<dep[b])
		swap(a,b);
	int x=0;
	for(int j=L-1;j>=0;j--)
		if(dep[a]-dep[b]>=(1<<j))
			x^=up[a][j].s,a=up[a][j].f;	
	for(int j=L-1;j>=0;j--)
		if(up[a][j].f!=up[b][j].f)
			x^=up[a][j].s^up[b][j].s,a=up[a][j].f,b=up[b][j].f;
	x^=up[a][0].s^up[b][0].s;
	assert(up[a][0].f==up[b][0].f);
	return x;
}
map<int,int> maskId;
map<pair<int,int>,bool> ok;
vector<int> msks;
vector<vector<int> > setBits;
void gen(int tr,int msk){
    if(ok.find({tr,msk})!=ok.end())
        return;
    if(maskId.find(msk)==maskId.end())
        maskId[msk]=maskId.size()-1;
    ok[{tr,msk}]=1;
    if(tr==W)
        return;
    gen(tr+1,msk);
    if((msk&(1<<tr-1))==0){
        int nov=msk|(1<<tr-1);
        for(int i=0;i<W;i++)
            if(msk&(1<<i-1))
                nov|=(1<<(tr^i)-1);
        gen(tr+1,nov);
    }
}
int combineMasks(int a,int b,vector<int> &aa,vector<int> &bb){
	if(b==0)
		return a;
	if(a==0)
		return b;
	int sol=a|b;
	for(auto i:aa)
		for(auto j:bb)
			sol|=1<<((i+1)^(j+1))-1;
	return sol;
}
struct component{
	int t,a;
	vector<bool> ma,mb;
	int masks[3];
	vector<int> sledece[3];
	component(int tt,int aa,vector<bool> c1,vector<bool> c2){
		t=tt;
		a=aa;
		ma=c1;
		mb=c2;
	}
	void calculateCases(){
		if(t==0){
			masks[0]=0;
			sledece[0].resize(C);
			for(int i=0;i<C;i++)
				sledece[0][i]=i;
			masks[2]=-1;
			if(ma[0])
				masks[1]=-1;
			else{
				int msk=0;
				vector<int> se;
				for(int i=1;i<W;i++)
					if(ma[i])
						msk|=1<<i-1,se.pb(i-1);
				masks[1]=msk; 
				sledece[1].resize(C);
				for(int i=0;i<C;i++)
					if(masks[1]&msks[i])
						sledece[1][i]=-1;
					else
						sledece[1][i]=maskId[combineMasks(msks[i],masks[1],setBits[i],se)];
			}
		}
		else{
			masks[0]=0;
			sledece[0].resize(C);
			for(int i=0;i<C;i++)
				sledece[0][i]=i;
			vector<bool> nov(W);
			for(int i=0;i<W;i++)
				nov[i]=ma[i]||mb[i];
			for(int i=0;i<W;i++)
				if(ma[i])
					for(int j=0;j<W;j++)
						if(mb[j])
							nov[i^j]=1;
			if(nov[0])
				masks[1]=-1;
			else{
				int msk=0;
				vector<int> se;
				for(int i=1;i<W;i++)
					if(nov[i])
						msk|=1<<i-1,se.pb(i-1);
				masks[1]=msk; 
				sledece[1].resize(C);
				for(int i=0;i<C;i++)
					if(masks[1]&msks[i])
						sledece[1][i]=-1;
					else
						sledece[1][i]=maskId[combineMasks(msks[i],masks[1],setBits[i],se)];
			}
			vector<bool> novnov=nov;
			novnov[a]=1;
			for(int i=0;i<W;i++)
				if(nov[i])
					novnov[i^a]=1;
			if(novnov[0])
				masks[2]=-1;
			else{
				vector<int> se;
				int msk=0;
				for(int i=1;i<W;i++)
					if(novnov[i])
						msk|=1<<i-1,se.pb(i-1);
				masks[2]=msk;
				sledece[2].resize(C);
				for(int i=0;i<C;i++)
					if(masks[2]&msks[i])
						sledece[2][i]=-1;
					else
						sledece[2][i]=maskId[combineMasks(msks[i],masks[2],setBits[i],se)];
			}
		}
	}
	void print(){
		printf("t: %i, a: %i\n",t,a);
		cout << ma << endl << mb << endl;
	}
};
int broj;
vector<component> comps;
vector<vector<int> > dp;
int calc(int ind,int tr){
		if(tr==broj)
			return 1;
		if(dp[ind][tr]!=-1)
			return dp[ind][tr];
		int myMask=msks[ind];
		dp[ind][tr]=0;
		for(int i=0;i<3;i++){
			if(comps[tr].masks[i]!=-1&&comps[tr].sledece[i][ind]!=-1){
				int ans=calc(comps[tr].sledece[i][ind],tr+1);
				if(i==1&&comps[tr].t==1)
					dp[ind][tr]=add(dp[ind][tr],add(ans,ans));
				else
					dp[ind][tr]=add(dp[ind][tr],ans);
			}
		}
		return dp[ind][tr];
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	gen(1,0);
	vector<pair<int,int> > pls;
	for(auto p:maskId)
		pls.pb({p.s,p.f});
	sort(all(pls));
	for(auto p:pls)
		msks.pb(p.s);
	for(auto p:msks){
		vector<int> set;
		for(int i=0;i<W-1;i++)
			if(p&(1<<i))
				set.pb(i);
		setBits.pb(set);
	}
	iota(all(par),0);
	int n,m;
	scanf("%i %i",&n,&m);
	if(n==1){
		printf("1\n");
		return 0;
	}
	vector<pair<pair<int,int>,int> > edges,other,novo;
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%i %i %i",&a,&b,&c);
		a--;b--;
		if(a==0)
			one[b]=c;
		if(b==0)
			one[a]=c;
		if(a&&b)
			edges.pb({{a,b},c});
	}
	for(auto p:edges)
		if(one[p.f.f]!=-1&&one[p.f.s]!=-1)	
			other.pb(p);
		else
			novo.pb(p);
	edges=novo;
	novo.clear();
	for(auto p:edges){
		if(merge(p.f.f,p.f.s))
			graf[p.f.f].pb({p.f.s,p.s}),graf[p.f.s].pb({p.f.f,p.s});
		else
			novo.pb(p);
	}
	edges=novo;
	for(int i=0;i<n;i++)
		if(one[i]!=-1)
			up[i][0]={i,0},dfs(i,i);
	for(int j=1;j<L;j++)
		for(int i=0;i<n;i++)
			up[i][j]={up[up[i][j-1].f][j-1].f,up[i][j-1].s^up[up[i][j-1].f][j-1].s};
	for(auto p:edges){
		int c=find(p.f.f),x=getXor(p.f.f,p.f.s)^p.s;
		bool novo[W]={};
		novo[x]=1;
		for(int i=0;i<W;i++)
			if(moze[c][i])
				novo[i]=novo[i^x]=1;
		for(int i=0;i<W;i++)
			moze[c][i]=novo[i];
	}
	for(auto p:other){
		done[p.f.f]=done[p.f.s]=1;
		component tr(1,one[p.f.f]^one[p.f.s]^p.s,moze[find(p.f.f)],moze[find(p.f.s)]);
		comps.pb(tr);
	}
	int multiplier=1;
	for(int i=0;i<n;i++)
		if(one[i]!=-1&&!done[i]){
			if(moze[find(i)][0])
				continue;
			bool prazno=1;
			for(int j=0;j<W;j++)
				if(moze[find(i)][j])
					prazno=0;
			if(prazno){
				multiplier=mul(multiplier,2);
				continue;
			}
			component tr(0,-1,moze[find(i)],moze[find(i)]);
			comps.pb(tr);
		}
	for(auto &p:comps)
		p.calculateCases();
	broj=comps.size();
	dp.resize(C,vector<int>(broj,-1));
	printf("%i\n",mul(multiplier,calc(0,0)));
	return 0;
}