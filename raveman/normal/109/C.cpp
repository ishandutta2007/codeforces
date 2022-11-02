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

ll res;
int n;
vector<pii> v;

int p[111111];
int c[111111];
ll  x[111111];

int P(int v){return v==p[v] ? v : p[v] = P(p[v]);}

bool good(int x){
	while(x){
		if(x%10!=4 && x%10!=7) return 0;
		x/=10;
	}
	return 1;
}

void join(int p1,int p2){
	c[P(p1)] += c[P(p2)];
	p[P(p2)] = P(p1);
}

void join2(int p1,int p2){
	p1 = P(p1);
	p2 = P(p2);
	
	ll c1 = c[p1];
	ll c2 = c[p2];

	res += c1 * c2 * (c2-1);
	res += c2 * c1 * (c1-1);
	res += 2 * x[p1] * c2;
	res += 2 * x[p2] * c1;

	x[p1] += x[p2];
	x[p1] += c1 * c2 * 2;

	c[p1] += c[p2];
	p[p2] = p1;
}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif
#ifndef LocalHost
	//freopen("dices.in","r",stdin);
	//freopen("dices.out","w",stdout);
#endif

	cin>>n;
	REP(i,n) p[i]=i,c[i]=1,x[i]=0;

	REP(i,n-1){
		int X,y,z;
		scanf("%d %d %d",&X,&y,&z);
		X--,y--;
		if(good(z)) v.pb(pii(X,y));
		else join(X,y);
	}

	REP(i,v.size())
		join2(v[i].first,v[i].second);

	cout<<res<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}