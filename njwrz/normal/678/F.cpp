/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
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
using namespace std;
int l[300005],r[300005],q[300005],ques[300005],mini=-2e18;
P<int,int> p[300005];
V<int> vp; 
V<int> v[1<<20];
V<double> vd[1<<20];
bool cmp(int x,int y){
	RE p[x].F<p[y].F;
}
double solve(int x,int y){
	RE 1.0*(p[x].S-p[y].S)/(p[y].F-p[x].F);
}
void update(int x,int it){
//	cout<<1;
	while(!v[x].empty()&&p[v[x].back()].F==p[it].F&&p[v[x].back()].S<=p[it].S){
		v[x].pop_back();
		if(!v[x].empty())vd[x].pop_back();
	}
	while(v[x].size()>1&&solve(v[x][v[x].size()-2],it)>solve(v[x][v[x].size()-1],it)){
		v[x].pop_back();vd[x].pop_back();
	}
	v[x].PB(it);
	if(v[x].size()>1)vd[x].PB(solve(v[x][v[x].size()-2],it));
//	cout<<2;
}
void update(int x,int l,int r,int tl,int tr,int it){
	if(tl>r||l>tr)RE;
	if(tl<=l&&tr>=r){
		update(x,it);RE ;
	}
	int mid=(l+r)>>1;
	update(x<<1,l,mid,tl,tr,it);
	update((x<<1)|1,mid+1,r,tl,tr,it);
}
int get(int x,int it,int pos){
//	if(pos==45){
//		for(auto u:v[x])cout<<u<<' ';
//		for(auto u:vd[x])cout<<u<<' ';
//		cout<<'\n';
//	}
	if(v[x].empty()){
		RE mini;
	}else if(vd[x].empty()){
		P<int,int> t=p[v[x].back()];
		RE t.F*it+t.S;
	}else{
		int iter=lwb(ALL(vd[x]),1.0*it)-vd[x].begin();
		P<int,int> t=p[v[x][iter]];
		RE t.F*it+t.S;
	}
}
int query(int x,int l,int r,int it,int pos){
	int re=get(x,it,pos);
	if(l==r)RE re;
	int mid=(l+r)>>1;
	if(mid>=pos){
		gmax(re,query(x<<1,l,mid,it,pos));
	}else gmax(re,query((x<<1)|1,mid+1,r,it,pos));
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	cout<<mini<<'\n';
	int n;
	cin>>n;
	FOR(i,1,n){
		cin>>q[i];
		if(q[i]==1){
			cin>>p[i].F>>p[i].S;
			vp.PB(i);
			l[i]=i;r[i]=n;
		}else if(q[i]==2){
			int x;
			cin>>x;
			r[x]=i;
		}else{
			cin>>ques[i];
		}
	}
	sort(ALL(vp),cmp);
	for(auto u:vp){
		update(1,1,n,l[u],r[u],u);
//		cout<<l[u]<<' '<<r[u]<<'\n';
	}
//	RE 0;
	FOR(i,1,n)if(q[i]==3){
		int t=query(1,1,n,ques[i],i);
		if(t==mini){
			cout<<"EMPTY SET\n";
		}else cout<<t<<'\n';
	}
	RE 0;
}