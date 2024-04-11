#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

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

int n,k;
pii a[111111];
int root;
int par[111111];
int val[111111];
vi v[111111];
int m[111111];
int M[111111];

const int st = 1<<18;

ll s1[2*st];
ll s2[2*st];

void add(ll *s,int beg,int end,int val){
	beg += st;
	end += st;
	while(beg<=end){
		if(beg&1) s[beg] += val;
		if(!(end&1)) s[end] += val;
		beg = (beg + 1)>>1;
		end = (end - 1)>>1;
	}
}
ll getSum(ll *s,int pos){
	ll res = 0;
	pos += st;
	while(pos){
		res += s[pos];
		pos>>=1;
	}
	return res;
}

void dfs(int ver){
	if(v[ver].size()==0){
		m[ver] = M[ver] = val[ver];
	}else{
		dfs(v[ver][0]);
		dfs(v[ver][1]);
		m[ver] = m[v[ver][0]];
		M[ver] = M[v[ver][1]];
	}
}
void go(int ver,int beg,int end){
	if(beg>end) return;
	if(v[ver].size()==0) return;

	int B = beg, E = end;
	int best = end+1;
	while(B<=E){
		int s = (B+E)/2;
		if(a[s].first > val[ver]){
			best = s;
			E = s-1;
		}else B = s+1;
	}

	add(s2,beg,end,1);
	
	add(s1,beg,best-1,m[v[ver][1]]);
	add(s1,best,end,M[v[ver][0]]);

	go(v[ver][0], beg, best-1);
	go(v[ver][1], best, end);
}

double r[111111];

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	cin>>n;
	REP(i,n){
		scanf("%d %d",par+i,val+i);
		if(par[i]==-1) root = i;
		else par[i]--;
		if(par[i]!=-1) v[par[i]].pb(i);
	}
	cin>>k;
	REP(i,k){scanf("%d",&a[i].first);a[i].second=i;}
	sort(a,a+k);
	
	REP(i,n) if(v[i].size() && val[v[i][0]] > val[i]) swap(v[i][0],v[i][1]);
	dfs(root);
	go(root,0,k-1);

	REP(i,k){
		r[a[i].second] = double(getSum(s1,i))/getSum(s2,i);
	}

	REP(i,k) printf("%.10lf\n",r[i]);

	return 0;
}