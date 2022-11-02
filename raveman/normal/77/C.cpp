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

int n;
int a[111111];
vi  v[111111];
int s;

typedef pair<ll,ll> pl;

pl go(int ver,int par=-1){
	vector<pl> vv;
	REP(i,v[ver].size()) if(v[ver][i]!=par)
		vv.pb(go(v[ver][i],ver));
	if(vv.size()==0) return pl(0,a[ver]);
	SORT(vv);
	reverse(vv.begin(),vv.end());
	
	ll total = 0;
	REP(i,vv.size())if(a[ver]>=1){
		a[ver]--;
		total += 1 + 1 + vv[i].first;
	}
	REP(i,vv.size()){
		int z = min((int)vv[i].second,a[ver]);
		total += 2*z;
		a[ver]-=z;
	}
	return pl(total,a[ver]);
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

	cin>>n;
	REP(i,n) scanf("%d",a+i);
	REP(i,n-1){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	cin>>s;s--;
	REP(i,n)if(i!=s) a[i]--;
	cout<<go(s).first<<endl;

	return 0;
}