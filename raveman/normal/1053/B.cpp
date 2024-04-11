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
#include<stack>
#include<unordered_map>
#include<unordered_set>

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

ll n;
ll a[333333];
int b[333333];
int c[333333];

ll nb(ll x){return x?1+nb(x&(x-1)):0;}

int s[1<<20];
void setVal(int pos,int c){
	pos += (1<<19);
	while(pos){
		s[pos] += c;
		pos>>=1;
	}
}
int getSum(int p1,int p2){
	p1+=(1<<19);
	p2+=(1<<19);
	int sum=0;
	while(p1<=p2){
		if(p1&1)sum+=s[p1];
		if(!(p2&1))sum+=s[p2];
		p1=(p1+1)>>1;
		p2=(p2-1)>>1;
	}
	return sum;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)scanf("%I64d",a+i),b[i]=nb(a[i]);
	c[0]=b[0]%2;
	FOR(i,1,n){
		c[i] = c[i-1] + b[i];
		c[i]%=2;
	}
	REP(i,n)setVal(i,c[i]);
	ll res = 0;
	//REP(i,n)cout<<c[i]<<' ';puts("");
	REP(i,n){
		int t = getSum(i,n-1);
		if(i&&c[i-1])t=(n-i)-t;

		t=(n-i)-t;
		//cout<<i<<' '<<t<<endl;
		
		res += t;

		int sum = 0;
		int mx = 0;
		for(int j=i;j<n;j++){
			sum += b[j];
			mx=max(mx,b[j]);
			if(sum-mx<mx && sum%2==0) res--;

			if(sum>200)break;
		}
		//cout<<i<<" : "<<res<<endl;
	}
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}