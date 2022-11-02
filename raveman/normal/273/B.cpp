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
map<int, vi > w;

ll go(int n,int m,int mod){
	ll res = 1;
	for(int i=2;i<=n;i++){
		int t = i;
		while(m && (t%2==0)){
			t/=2;
			m--;
		}
		res *= t;
		res %= mod;
	}

	return res;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(j,2)REP(i,n){int x;scanf("%d",&x);w[x].pb(i);}
	int m;
	cin>>m;

	ll res = 1;
	for(map<int,vi>::iterator it = w.begin();it!=w.end();it++){
		vi temp = it->second;
		SORT(temp);
		vi t2 = temp;
		UN(t2);
		int num = temp.size() - t2.size();
		res *= go(temp.size(), num, m);
		res %= m;
	}
	cout<<res<<endl;

	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}