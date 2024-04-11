#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
using namespace std;
const int N=1e5+9;
queue<int> q;
struct node{
	int id,t;
	bool operator < (const node &a) const{
		return id>a.id;
	}
}nod[N];
bool cmp(node a,node b){
	if(a.t^b.t)return a.t<b.t;
	return a.id<b.id;
}
ll ans[N];
int main()
{
	int n,p,cnt=0;
	scanf("%d%d",&n,&p);
	rep(i,0,n){
		int t;
		scanf("%d",&t);
		nod[cnt++]=(node){i+1,t};
	}
	sort(nod,nod+n,cmp);
	priority_queue<node> PQ;
	ll now=0;
	cnt=0;
	int last=0,head=n+1;
	while(cnt<n){
		for(;last<n;++last){
			if(nod[last].t>now)break;
			if(nod[last].id<head)q.push(nod[last].id),head=nod[last].id;
			else PQ.push((node){nod[last].id,nod[last].t});
		}
		if(q.empty()){
			head=n+1;
			if(PQ.empty()){
				now=nod[last].t;
				for(;last<n;++last){
					if(nod[last].t>now)break;
					if(nod[last].id<head)q.push(nod[last].id),head=nod[last].id;
					else PQ.push((node){nod[last].id,nod[last].t});
				}
			}
			else{
				node u=PQ.top();
				PQ.pop();
				q.push(u.id);
				head=u.id;
			}
		}
		int u=q.front();
		q.pop();
		//cout<<now<<' '<<u.id<<"now\n";
		now=now+p;
		ans[u]=now;
		++cnt;
	}
	rep(i,1,n+1)printf("%lld ",ans[i]);
}
/*
6 1000000000
515693 916406 306579 117861 485709 804227
*/