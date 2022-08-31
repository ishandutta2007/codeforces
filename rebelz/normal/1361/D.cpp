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
typedef long double ld;
typedef pair<ld,ll> pdi;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k;
ll x[500005],y[500005],now[500005];
ld val[500005],sumr[500005],suml[500005];
vector<ld> g[500005];
map<pll,vector<ld> > v;
priority_queue<pdi> q;

ld getval(int id,int num){
	if(k-num-num+1>=0){
		sumr[id]+=g[id][g[id].size()-num];
		return g[id][g[id].size()-num]*(k-num-num+1);
	}
	else{
		ld tmp=(k-(k+1)/2*2-1)*g[id][num-(k+1)/2-1]-suml[id]-suml[id];
		suml[id]+=g[id][num-(k+1)/2-1];
		return tmp;
	}
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) x[i]=readint(),y[i]=readint();
	for(int i=1;i<=n;i++){
		ll g=__gcd(abs(x[i]),abs(y[i]));
		if(!g) continue;
		v[mp(x[i]/g,y[i]/g)].pb(sqrt(x[i]*x[i]+y[i]*y[i]));
	}
	for(auto r:v) g[++m]=r.se;
	for(int i=1;i<=m;i++) sort(g[i].begin(),g[i].end());
	for(int i=1;i<=m;i++) q.push(mp(getval(i,now[i]+1),i));
	ld ans=0;
	bool fl=0;
	for(int i=1;i<=k;i++){
		if(!fl&&(q.empty()||q.top().fi<0)){
			fl=1;
			continue;
		}
		pdi tmp=q.top(); q.pop();
		now[tmp.se]++;
		ans+=tmp.fi;
//		cout<<"test "<<tmp.se<<' '<<tmp.fi<<endl;
		if(now[tmp.se]!=g[tmp.se].size()&&now[tmp.se]!=k) q.push(mp(getval(tmp.se,now[tmp.se]+1),tmp.se));
	}
	printf("%.15Lf\n",ans);
	return 0;
}