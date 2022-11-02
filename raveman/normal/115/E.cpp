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

typedef pair<pii,int> p3;

int n,m;
int p[222222];
p3  s[222222];
priority_queue<pii> q;

ll M[1<<20];
ll A[1<<20];

ll getmax(int a,int b,int L = 0, int R = 262143,int pos=1){
	if(b<L || a>R) return -1000000000000000000ll;
	if(a<=L && b>=R) return M[pos] + A[pos];
	ll val = getmax(a,b,L,(L+R)>>1,pos*2);
	val = max(val, getmax(a,b,1+((L+R)>>1),R,pos*2+1));
	return val;
}

void addVal(int a,int b,ll val,int L = 0, int R = 262143,int pos=1){
	if(b<L || a>R) return;
	if(a<=L && b>=R) { A[pos] += val; return; }

	addVal(a,b,val,L,(L+R)>>1,pos*2);
	addVal(a,b,val,1+((L+R)>>1),R,pos*2+1);

	M[pos] = max(M[pos*2]+A[pos*2],M[pos*2+1]+A[pos*2+1]);
}


int main(){ 

#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n) scanf("%d",p+i);
	REP(i,m) scanf("%d %d %d",&s[i].first.first,&s[i].first.second,&s[i].second);
	REP(i,m) swap(s[i].first.first,s[i].first.second),s[i].first.second=-s[i].first.second;
	sort(s,s+m);
	REP(i,m) swap(s[i].first.first,s[i].first.second),s[i].first.first=-s[i].first.first,s[i].first.first--,s[i].first.second--;
	
	int j = 0;
	REP(i,n){
		addVal(222222-i,222222-i, getmax(222222-i+1, 222223));
		addVal(222222-i+1,222223, -p[i]);
		while(j<m && s[j].first.second==i)
			addVal(222222-i+s[j].first.second-s[j].first.first+1,222223,s[j].second),j++;
	}

	cout<<getmax(0,222223)<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}