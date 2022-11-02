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

string s;
bool  a[222222];
unordered_map<int,int> om;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	const int LIM=152;
	cin>>s;
	//REP(i,200000)s.pb('0'+rand()%2);
	int n = s.size();
	REP(i,n)if(s[i]=='0')a[i]=0;else a[i]=1;
	ll res = 0;
	//small
	FOR(k,1,LIM){
		om.clear();
		om[0]=1;
		int sum = 0;
		REP(i,n){
			if(a[i])sum+=k-1;
			else sum--;
			om[sum]++;
		}
		for(unordered_map<int,int>::iterator it=om.begin();it!=om.end();it++){
			res += it->second * ll(it->second-1)/2;
		}
	}
	//large
	vi ones;
	REP(i,n)if(s[i]=='1')ones.pb(i);
	int oz = ones.size();
	REP(i,oz){
		int toz = min(oz,i+2000);
		for(int j=i;j<toz;j++){
			int nones = j-i+1;
			int nzeros = ones[j]-ones[i]+1-nones;
			int rg = (j+1>=oz?n:ones[j+1])-ones[j]-1;
			int lf = ones[i] - (i-1>=0?ones[i-1]:-1)-1;

			for(int k=LIM;k<=n;k++){
				//cout<<k<<' '<<nones<<' '<<nzeros<<' '<<lf<<' '<<rg<<endl;
				if(nones*ll(k-1)>nzeros + rg + lf)break;
				int r = nones*(k-1)-nzeros;
				if(r>=0)res += 	min(r,rg)-max(r-lf,0)+1;
			}
			// nones .. nzeros + 0..rg + 0..lf
		}
	}

	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}