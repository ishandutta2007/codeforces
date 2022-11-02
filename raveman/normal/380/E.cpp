#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
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

using namespace std;


typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n;
int b[333333];
vector<pii> t;

int rv[333333];


struct Node{
	Node *lf;
	Node *rg;
	int l,r;
	int mx;
	Node(){
		lf=rg=0;
		mx=0;
	}
};

Node *root;

Node *buildTree(int from, int to){
	Node* res = new Node();
	res->l = from;
	res->r = to;
	if(from!=to){
		res->lf = buildTree(from,(from+to)/2);
		res->rg = buildTree((from+to)/2+1,to);
	}
	return res;
}

void setValue(Node *curr,  int pos, int val){
	if(!curr) return;
	if(curr->l > pos || curr->r < pos ) return;
	curr->mx=max(curr->mx, val);
	setValue(curr->lf, pos, val);
	setValue(curr->rg, pos, val);
}

int getBiggerL(Node *curr, int to, int val){
	if(!curr) return -1;
	if(curr->mx <= val) return -1;
	if(curr->l > to) return -1;
	if (curr->l == curr->r) return curr->l;
	int p1 = getBiggerL(curr->rg, to, val);
	if(p1!=-1) return p1;
	return getBiggerL(curr->lf, to, val);
}

int getBiggerR(Node *curr, int from, int val){
	if(!curr) return -1;
	if(curr->mx <= val) return -1;
	if(curr->r < from) return -1;
	if (curr->l == curr->r) return curr->l;
	int p1 = getBiggerR(curr->lf, from, val);
	if(p1!=-1) return p1;
	return getBiggerR(curr->rg, from, val);
}

double pw[111111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	pw[0]=1;
	FOR(i,1,111111)pw[i]=pw[i-1]/2;
	cin>>n;
	REP(i,n)scanf("%d",b+i),t.pb(pii(b[i],i));
	SORT(t);
	root = buildTree(0,n-1);
	REP(i,n){
		rv[t[i].second] = i + 1;
		setValue(root, t[i].second, i + 1);
	}

	const int lim = 20;
	double sum = 0;
	vi l,r;
	double den = 1./ n/n;
	l.reserve(lim),r.reserve(lim);
	REP(i,n){
		l.clear(),r.clear();
		int curr = i;
		while(1){
			int pos = getBiggerL(root, curr - 1, rv[i]);
			if(pos==-1){
				l.pb(curr+1);
				break;
			}else{
				l.pb(curr-pos);
				curr=pos;
			}
			if(l.size()==lim) break;
		}
		curr = i;
		while(1){
			int pos = getBiggerR(root, curr + 1, rv[i]);
			if(pos==-1){
				r.pb(n-curr);
				break;
			}else{
				r.pb(pos - curr);
				curr=pos;
			}
			if(r.size()==lim) break;
		}
		REP(i1,l.size())REP(i2,r.size()){
			sum += b[i]*den * l[i1] * r[i2] * pw[i1+i2+1];
		}
	}
	printf("%.10lf\n",sum);

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}