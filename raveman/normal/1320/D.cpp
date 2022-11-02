#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<cstring>
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
typedef pair<int,pii>	p3;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back


int nz[222222];
int pz[222222];
int n,q;
string t;

vi pos;
vi val;

ll mod1 = 1000000007;
ll mod2= 10007;
ll mst1[222222];
ll mst2[222222];
ll h1[222222];
ll h2[222222];

ll getH(int p1,int p2,ll* h,ll* s){
	return h[p2]-(p1-1>=0?h[p1-1]:0)*s[p2-p1+1];
}

pl getHash(int p1,int p2){
	p1=lower_bound(pos.begin(),pos.end(),p1)-pos.begin();
	p2=lower_bound(pos.begin(),pos.end(),p2)-pos.begin();
	return pl(getH(p1,p2,h1,mst1),getH(p1,p2,h2,mst2));
}

vector<ll> gethash(int p1,int len){
	vector<ll> hh;
	int p2 = p1 + len - 1;
	if(nz[p1] > p2){
		// all1
	}else{
		int fz = nz[p1];
		int lz = pz[p2];
		pl h = getHash(fz,lz);
		if(t[p1]=='1' && (fz-p1)%2==1)hh.pb(1);
		else hh.pb(0);
		hh.pb(h.first);
		hh.pb(h.second);
		if(t[p2]=='1' && (p2-lz)%2==1)hh.pb(1);
		else hh.pb(0);
	}
	//REP(i,hh.size()) cout<<hh[i]<<' ';puts("");
	return hh;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	mst1[0]=mst2[0]=1;
	FOR(i,1,222222){
		mst1[i]=mst1[i-1]*mod1;
		mst2[i]=mst2[i-1]*mod2;
	}

	cin>>n;
	cin>>t;
	nz[n]=n;
	for(int i=n-1;i>=0;i--){
		nz[i]=(t[i]=='0'?i:nz[i+1]);
	}
	REP(i,n){
		pz[i]=(t[i]=='0'?i:(i-1>=0?pz[i-1]:-1));
	}
	REP(i,t.size()){
		if(t[i]=='1' && !val.empty() && val.back()==1){val.pop_back();pos.pop_back();continue;}
		val.pb(t[i]-'0');
		pos.pb(i);
	}
	REP(i,val.size()){
		h1[i]=(i-1>=0?h1[i-1]:0)*mod1+val[i]+1;
		h2[i]=(i-1>=0?h2[i-1]:0)*mod2+val[i]+1;
	}
	cin>>q;
	REP(i,q){
		int l1,l2,len;
		scanf("%d %d %d",&l1,&l2,&len);
		l1--,l2--;
		if(gethash(l1,len)==gethash(l2,len))puts("Yes");
		else puts("No");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}