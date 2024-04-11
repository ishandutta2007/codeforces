#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int T,n,m,x,y,tot,a[N];
struct node{
	int l,r,v;
	friend bool operator < (node x,node y){
		if(x.l!=y.l)return x.l<y.l;
		else if(x.r!=y.r)return x.r<y.r;
		else return x.v<y.v;
	}
}l[N];
set<node>s;
void work(int u){
	while(1){
		auto tmp=--(s.upper_bound({u,1000000000,1000000000}));
		auto test=s.upper_bound({u,1000000000,1000000000});
		if(tmp!=(--s.end())){
			auto nxt=next(tmp);
			if((*tmp).v>(*nxt).v)return ;
			node tep=*nxt;
			node tap=*tmp;
			s.erase(nxt);
			s.erase(tmp);
			s.insert({tap.l,tep.r,tap.v});
		}
		else break;
	}
}
signed main(){
//	freopen("data.in","r",stdin);
	cin>>T;
//	T=1;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		l[++tot]={1,1,a[1]}; 
		for(int i=2;i<=n;i++){
			if(l[tot].v<=a[i]){
				l[tot].r=i;
			}
			else{
				l[++tot]={i,i,a[i]};
			}
		}
		for(int i=1;i<=tot;i++)s.insert(l[i]);
		for(int i=1;i<=m;i++){
			scanf("%d%de",&x,&y);
			auto tmp=prev(s.upper_bound({x,1000000000,1000000000}));
			node tep=*tmp;
			a[x]-=y;
			if(tep.l==x){
				s.erase(tmp);
				tep.v=a[x];
				s.insert(tep);
				work(x);
			}
			else{
				if(a[x]<tep.v){
					s.erase(tmp);
					s.insert({tep.l,x-1,tep.v});
					s.insert({x,tep.r,a[x]});
					work(x);
				}
			}
			cout<<s.size()<<' ';
		}
		cout<<'\n';
		s.clear();
		tot=0;
	}
	return 0;
}