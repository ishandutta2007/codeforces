#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <cassert>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;	 
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for (int i(a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

int _x,_y,_p,_r,n;
int x[255555];
int y[255555];
int m[255555];
int p[255555];
int r[255555];

vi M;
vector<ll> D;
queue<pii> q;
int res;

struct Node{
	int l,r;
	Node *lf;
	Node *rg;
	int sum;
	int id;
	Node *other;
	Node(){l=r=sum=0;lf=rg=other=0;id=-1;}
};

Node *buildTree(int l,int r){
	Node *curr = new Node();
	curr->l = l;
	curr->r = r;
	if(l!=r){
		curr->lf = buildTree(l,(l+r)/2);
		curr->rg = buildTree((l+r)/2+1,r);
	}
	return curr;
}

Node *update(Node *curr, int pos,int val){
	if(curr->l > pos || curr->r < pos) return curr;
	Node *tmp = new Node();
	tmp->l = curr->l;
	tmp->r = curr->r;
	if(curr->lf){
		tmp->lf = update(curr->lf, pos, val);
		tmp->rg = update(curr->rg, pos, val);
		tmp->sum = tmp->lf->sum + tmp->rg->sum;
	}else{
	  tmp->other = curr;
		tmp->id = val;
		tmp->sum = 1 + curr->sum;
	}
	return tmp;
}

Node *root[250111];
bool u[250111];

void go_parse(Node *curr, int dd){
	if(curr->l > dd || curr->sum==0) return;
	if(curr->lf){
		go_parse(curr->lf, dd);
		go_parse(curr->rg, dd);
		curr->sum = curr->lf->sum + curr->rg->sum;
	}else{
		//cout<<curr->v.size()<<endl;
		if(curr->id!=-1 && !u[curr->id]){
			res++;
			u[curr->id] = true;
			q.push(pii(p[curr->id], r[curr->id]));
		}
		go_parse(curr->other, dd);
		curr->id = -1;
		curr->sum = 0;
	}
}

void go(int mm,int dd){
	Node *curr = root[mm+1];
	go_parse(curr, dd);
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>_x>>_y>>_p>>_r>>n;
	REP(i,n){
		scanf("%d %d %d %d %d",x+i,y+i,m+i,p+i,r+i);
		x[i]-=_x;
		y[i]-=_y;
		M.pb(m[i]);
		D.pb(x[i]*ll(x[i])+y[i]*ll(y[i]));
	}
	UN(M);UN(D);

	vector< pair<pii,int> > vv;
	REP(i,n){
		int m_pos = lower_bound(M.begin(),M.end(),m[i])-M.begin();
		ll  dd = x[i] * ll(x[i]) + y[i] * ll(y[i]);
		int d_pos = lower_bound(D.begin(),D.end(),dd)-D.begin();

		vv.pb(make_pair(pii(m_pos,d_pos),i));
	}
	SORT(vv);
	root[0] = buildTree(0,250111);
	REP(i,vv.size()) root[vv[i].first.first+1] = update((i==0 || vv[i-1].first.first!=vv[i].first.first ? root[vv[i].first.first] : root[vv[i].first.first+1]), vv[i].first.second, vv[i].second);
	

	q.push(pii(_p,_r));
	while(!q.empty()){
		pii curr = q.front();q.pop();
		int mm = curr.first;
		ll  dd = curr.second * ll(curr.second);
		int m_pos = lower_bound(M.begin(),M.end(),mm+1)-M.begin();
		m_pos--;
		int d_pos = lower_bound(D.begin(),D.end(),dd+1)-D.begin();
		d_pos--;
		go(m_pos,d_pos);
	}
	cout<<res<<endl;

#ifdef LocalHost
	cerr<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}