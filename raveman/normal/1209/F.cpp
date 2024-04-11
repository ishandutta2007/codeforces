#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

const int mod = 1000000007;
int n,m;
vector<pii> v[111111];

int l[111111];
int d[111111];

struct Node{
	Node(){
		CL(nn,0);
		CL(p,0);
	}
	Node* nn[10];
	Node* p[20];
};

Node* tv[111111];
ll r[111111];
ll p10[10];

Node* buildNode(Node* p){
	Node* c = new Node();
	c->p[0]=p;
	FOR(i,1,20)if(c->p[i-1])c->p[i]=c->p[i-1]->p[i-1];
	return c;
}

Node* go(Node* c,int w){
	vi v;
	while(w){
		v.pb(w%10);
		w/=10;
	}
	reverse(v.begin(),v.end());
	REP(i,v.size()){
		if(!c->nn[v[i]])c->nn[v[i]]=buildNode(c);
		c=c->nn[v[i]];
	}
	return c;
}

bool smaller(Node* n1,Node* n2){
	if(n1==n2)return 1;

	Node* tn1=n1;
	Node* tn2=n2;
	for(int i=19;i>=0;i--)while(tn1->p[i]!=tn2->p[i])tn1=tn1->p[i],tn2=tn2->p[i];
	Node* p = tn1->p[0];
	REP(i,10)if(p->nn[i]==tn1)return 1;
	else if(p->nn[i]==tn2)return 0;

	return false;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	p10[0]=1;
	FOR(i,1,10)p10[i]=p10[i-1]*10%mod;
	FOR(i,1,111111)l[i]=l[i/10]+1;

	cin>>n>>m;
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(pii(y,i+1));
		v[y].pb(pii(x,i+1));
	}

	CL(d,-1);
	d[0]=0;
	priority_queue<pii> q;
	q.push(pii(0,0));
	while(!q.empty()){
		int len = -q.top().first;
		int ver = q.top().second;
		q.pop();
		if(d[ver]!=len)continue;
		REP(i,v[ver].size()){
			int nv = v[ver][i].first;
			int nl = l[v[ver][i].second] + len;
			if(d[nv]==-1 || d[nv]>nl){
				d[nv]=nl;
				q.push(pii(-d[nv],nv));
			}
		}
	}

	vector<pii> w;
	REP(i,n)w.pb(pii(d[i],i));
	SORT(w);
	tv[0] = new Node();
	REP(i,w.size()){
		int ver = w[i].second;
		Node* c = tv[ver];

		REP(j,v[ver].size()){
			int nv = v[ver][j].first;
			int nl = w[i].first + l[v[ver][j].second];
			if(d[nv]==nl){
				Node* e = go(c, v[ver][j].second);
				if(tv[nv]){
					if(smaller(tv[nv],e)) continue;
				}
				tv[nv]=e;
				r[nv]=(r[ver]*p10[l[v[ver][j].second]]+v[ver][j].second)%mod;
			}
		}
	}

	FOR(i,1,n)cout<<r[i]<<'\n';
	
#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}