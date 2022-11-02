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

vector<ll> f;

map<ll,ll> q[100];
int solve(ll c,int n){
	if(c==0) return 1;
	if(n<0) return 0;
	if(q[n].count(c)) return q[n][c];
	int num = 0;
	if(n>=0 && c>=f[n]) num += solve(c-f[n],n-1);
	num += solve(c,n-1);
	return q[n][c]=num;
}

ll good(ll n,int pos){
	if(n<=2) return 1;
	if(f[pos]>n) return good(n,pos-1);
	if(q[pos].count(n)) return q[pos][n];
	ll k = n - f[pos];
	if(k<(pos<3 ? 0 : f[pos-3])) return q[pos][n]=good(f[pos-2]+k,pos)+good(k,pos);
	if(k<f[pos-2]) return q[pos][n]=2*good(k,pos);
	return q[pos][n]=good(f[pos+1]-2-k,pos);
}

ll d[111][2][2];

ll go(ll n){
	int pos = f.size();
	CL(d,0);
	d[pos][0][0] = 1;
	ll val;
	for(int i=pos;i;i--){
		REP(d1,2)REP(d2,2)if(val=d[i][d1][d2]){
			//cout<<i<<' '<<d1<<' '<<d2<<' '<<val<<' '<<n<<endl;
			int c1 = d1;
			int c2 = d2;
			if(n>=f[i-1]) c1++;

			if(c1<2 && c2+c1<2)
				d[i-1][c2+c1][c1]+=val;
			if(c1 && c2+c1-1<2)
				d[i-1][c2+c1-1][c1-1]+=val;
		}
		if(n>=f[i-1]) n-=f[i-1];
	}
	return d[0][0][0];
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	f.pb(1);
	f.pb(2);
	while(1){
		ll x = f.back() + f[f.size()-2];
		if(x>2000000000000000000ll) break;
		f.pb(x);
	}
	//for(int i=1;i<=300;i++)
	//	if(solve(i,f.size()-1)!=good(i,f.size()-1))
	//		cout<<i<<' '<<solve(i,f.size()-1)<<' '<<good(i,f.size()-1)<<' '<<solve(i,f.size()-1)-good(i,f.size()-1)<<endl;
	//cout<<good(1000000000000000000ll,f.size()-1)<<endl;
	int tc;
	cin>>tc;
	//tc=100000;
	REP(TC,tc){
		ll x;
		scanf("%I64d",&x);
		//x = 1000000000000000000ll-TC;//rand()*ll(rand());
		//x=1000-TC;
		REP(i,f.size()) q[i].clear();
		printf("%I64d\n",go(x));
		//go(x,f.size()-1);
	}
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}