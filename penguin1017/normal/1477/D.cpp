#include<bits/stdc++.h>
//#undef _GLIBCXX_HAVE_ICONV
//#include<bits/extc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
#define mp make_pair
using namespace std;
//using namespace __gnu_pbds;
const int N=5e5+9;
const int mod=998244353;
const ll Inf=1e18;
/*
inline int add(int a,const int &b){
	a+=b;
	if(a>=mod)a-=mod;
	return a;
}
inline int sub(int a,const int &b){
	a-=b;
	if(a<0)a+=mod;
	return a;
}
inline int mul(const int &a,const int &b){return 1ll*a*b%mod;}
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int jie[N],inv[N];
void pre(){
	inv[0]=inv[1]=1,jie[0]=1;
	rep(i,2,N)inv[i]=-1ll*mod/i*inv[mod%i]%mod+mod;
	rep(i,1,N)inv[i]=mul(inv[i],inv[i-1]),jie[i]=mul(jie[i-1],i);
}
inline int C(int m,int n){
	if(n>m||m<0||n<0)return 0;
	return mul(mul(jie[m],inv[n]),inv[m-n]);
}
*/
int belong[N];
int p[N],q[N];
set<pii> S[N],E;
vi g[N];
int cnt,id;
void build(int l,int r,int x){
	int pos=l;
//	cout<<l<<' '<<r<<"ok\n";
	for(auto w:S[x]){
		if(w.se==1)p[w.fi]=l,q[w.fi]=r;
		else{
		//	cout<<w.fi<<"???\n";
			p[w.fi]=pos+1,q[w.fi]=pos;
			++pos;
		}
	}
}
int deg[N];
int main(){
	//pre();
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		E.clear();
		cnt=0; 
		id=0;
		rep(i,1,n+1)belong[i]=0,deg[i]=0;
		rep(i,0,m){
			int u,v;
			scanf("%d%d",&u,&v);
			if(u>v)swap(u,v);
			if(E.find(mp(u,v))==E.end())E.insert(mp(u,v)),++deg[u],++deg[v];
		} 
		rep(i,1,n+1){
			if(deg[i]==n-1)p[i]=q[i]=++id;
			else if(belong[i])continue;
			else {
				rep(j,1,n+1){
					if(i==j)continue;
					int u=i,v=j;
					if(u>v)swap(u,v);
					if(E.find(mp(u,v))==E.end()){
					//	cout<<i<<' '<<j<<"??????\n";
						if(!belong[j]){
							++cnt;
							S[cnt].clear();
							S[cnt].insert(mp(u,0));
							S[cnt].insert(mp(v,0));
							belong[i]=cnt;
							belong[j]=cnt;
						}
						else{
							if(S[belong[j]].size()==2){
								auto it=S[belong[j]].begin();
								auto w=*it;
								++it;
								auto w2=*it;
								S[belong[j]].clear();
								if(w.fi==j)w2.se=0,w.se=1;
								else w2.se=1,w.se=0;
								S[belong[j]].insert(w);
								S[belong[j]].insert(w2);
								S[belong[j]].insert(mp(i,0));
								belong[i]=belong[j];
							}
							else{
								if(S[belong[j]].find(mp(j,1))==S[belong[j]].end()){
									S[belong[j]].erase(mp(j,0));
									++cnt;
									S[cnt].clear();
									S[cnt].insert(mp(u,0));
									S[cnt].insert(mp(v,0));
									belong[i]=cnt;
									belong[j]=cnt;
								}
								else{
									S[belong[j]].insert(mp(i,0));
									belong[i]=belong[j];
								}
							}
						}
						break;
					}
				}
			}
		}
		rep(i,1,cnt+1){
		//	cout<<i<<' '<<S[i].size()<<"check\n";
			if(S[i].size()==2){
				auto it=S[i].begin();
				auto w=*it;
				++it;
				auto w2=*it;
				if(w.se==w2.se)
				{
					w2.se=1; 
					S[i].erase(it);
					S[i].insert(w2);
				} 
			}
			build(id+1,id+S[i].size(),i);
			id+=S[i].size();
		}
		rep(i,1,n+1)printf("%d ",p[i]);
		puts("");
		rep(i,1,n+1)printf("%d ",q[i]);
		puts("");
	}
}