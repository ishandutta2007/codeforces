//#pragma comment(linker, "/STACK:60777216")  

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
typedef pair<int,pii>	p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n;
vector<pii> v[555555];

int d[555555];

int bfs(int ver){
	queue<int> q;	
	q.push(ver);
	CL(d,-1);
	d[ver]=0;
	int last=ver;
	while(!q.empty()){
		int ver = q.front();
		last=ver;
		q.pop();
		REP(i,v[ver].size()){
			int nver = v[ver][i].first;
			if(d[nver]==-1){
				d[nver]=d[ver]+1;
				q.push(nver);
			}
		}
	}
	return last;
}

int x[555555];
int y[555555];

int cnt;
int val[2][555555];
int from[2][555555];
int to[2][555555];
void dfs(int ver, int type,int par=-1,int num=0,int d=0){
	from[type][ver]=cnt;
	val[type][cnt]=(num%2==0?d:-d);
	cnt++;
	REP(i,v[ver].size()){
		int nver=v[ver][i].first;
		if(nver==par)continue;
		dfs(nver,type,ver,num+v[ver][i].second,d+1);
	}
	to[type][ver]=cnt-1;
}

struct Node{
	int l,r;
	Node* lf;
	Node* rg;
	int mx;
	int mn;
	bool f;
	Node(){
		l=r=0;
		lf=0;
		rg=0;
		mn=mx=0;
		f=0;
	}

};

Node* buildTree(int type, int l, int r){
	Node* c = new Node();
	c->l = l;
	c->r = r;
	if(l!=r){
		c->lf = buildTree(type,l,(l+r)/2);
		c->rg = buildTree(type,(l+r)/2+1,r);
		c->mx = max(c->lf->mx,c->rg->mx);
		c->mn = min(c->lf->mn,c->rg->mn);
	}else{
		c->mx = c->mn = val[type][l];
	}
	return c;
}

void swap(Node* curr){
	swap(curr->mn,curr->mx);
	curr->mn *= (-1);
	curr->mx *= (-1);
	
}

void inverse(Node* curr, int from, int to){
	if(curr->l > to)return;
	if(curr->r < from)return;
	if(from<=curr->l && curr->r<=to){
		curr->f ^= 1;
		swap(curr);
		//swap(curr->mn,curr->mx);
	}else{
		inverse(curr->lf,from,to);
		inverse(curr->rg,from,to);
		curr->mx = max(curr->lf->mx,curr->rg->mx);
		curr->mn = min(curr->lf->mn,curr->rg->mn);
		if(curr->f){
			swap(curr);//->mn,curr->mx);
		}
	}
	//cout<<curr->l<<' '<<curr->r<<' '<<curr->mn<<' '<<curr->mx<<endl;	
}

int solve(Node* curr){
	return curr->mx;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n-1){
		int z;
		scanf("%d %d %d",&x[i],&y[i],&z);
		x[i]--,y[i]--;
		v[x[i]].pb(pii(y[i],z));
		v[y[i]].pb(pii(x[i],z));
	}

	int v1 = bfs(0);
	int v2 = bfs(v1);
	
	cnt=0;

	dfs(v1,0);
	cnt=0;
	dfs(v2,1);

	//cout<<v1<<' '<<v2<<endl;

	Node* root1=buildTree(0,0,n-1);
	//REP(i,n)cout<<val[0][i]<<' ';puts("");
	Node* root2=buildTree(1,0,n-1);
	//REP(i,n)cout<<val[1][i]<<' ';puts("");

	int q;
	cin>>q;
	REP(i,q){
		int id;
		scanf("%d",&id);
		id--;

		int v1 = x[id];
		int v2 = y[id];
		REP(type,2){
			int lower;
			if (to[type][v2]-from[type][v2]<to[type][v1]-from[type][v1])lower=v2;
			else lower=v1;

			if(type==0){
				inverse(root1,from[type][lower],to[type][lower]);
			}else{
			//	cout<<"inv2 " << from[type][lower]<<" "<<to[type][lower]<<endl;
				inverse(root2,from[type][lower],to[type][lower]);
			}			
		}
		printf("%d\n",max(solve(root1), solve(root2)));
		//cout<<solve(root1)<<' '<<solve(root2)<<' '<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}