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

string s,t;
ll h1[1<<20];
ll m1[1<<20];
ll h2[1<<20];
ll m2[1<<20];

ll getH(ll* h, ll* m, int pos,int len){
	return h[pos+len-1]-(pos-1>=0?h[pos-1]:0)*m[len];
}
pl getH(int pos,int len){
	return pl(getH(h1,m1,pos,len),getH(h2,m2,pos,len));
}

bool good(int l0,int l1){
	pl h0,h1;
	bool hh0=false,hh1=false;
	int pos = 0;
	REP(i,s.size()){
		if(s[i]=='0'){
			pl x = getH(pos,l0);
			if(!hh0)h0=x,hh0=1;
			else if(h0!=x)return 0;
			pos += l0;
		}else{
			pl x = getH(pos,l1);
			if(!hh1)h1=x,hh1=1;
			else if(h1!=x)return 0;
			pos += l1;
		}
	}
	//cout<<"!"<<l0<<' '<<l1<<endl;
	//cout<<h0.first<<' '<<h0.second<<endl;
	//cout<<h1.first<<' '<<h1.second<<endl;
	if(l0==l1 && h0==h1)return 0;
	return 1;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>s>>t;
	ll n0=0,n1=0;
	REP(i,s.size())if(s[i]=='0')n0++;else n1++;

	m1[0]=m2[0]=1;
	ll md = rand()%10000+100000011;
	FOR(i,1,1<<20){
		m1[i]=m1[i-1]*md;
		m2[i]=m2[i-1]*1000000007;
	}
	REP(i,t.size()){
		h1[i]=(i-1>=0?h1[i-1]:0)*m1[1]+t[i]-'a'+1;
		h2[i]=(i-1>=0?h2[i-1]:0)*m2[1]+t[i]-'a'+1;
	}
	//REP(i,t.size()) cout<<h1[i]<<' ';puts("");

	int res = 0;
	FOR(l0,1,t.size()+1)if(n0*l0<t.size()){
		ll rem = t.size() - n0*l0;
		if(rem%n1==0){
			ll l1 = rem/n1;
			if(good(l0,l1)){
				res++;
			}
		}
	}
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}