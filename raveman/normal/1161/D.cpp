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

const int mod = 998244353 ;

ll qp(ll c,ll st){
	ll r=1;
	while(st){
		if(st&1)r*=c,r%=mod;
		c*=c,c%=mod;
		st>>=1;
	}
	return r;
}


int b[1111];
int a[1111];
bool visb[1111];
bool visa[1111];

vector<pii> vb[1111];
vector<pii> va[1111];

bool dfsb(int ver);

bool dfsa(int ver){
	//cout<<"dfsa "<<ver<<endl;
	if(visa[ver])return 0;
	visa[ver]=1;
	REP(i,va[ver].size()){
		int nver = va[ver][i].first;
		int nval = a[ver] ^ va[ver][i].second;
		//cout<<"try "<<nver<<endl;
		if(b[nver]!=-1 && b[nver]!=nval){
			return 1;
		}
		if(b[nver]!=-1)continue;
		b[nver]=nval;
		if(dfsb(nver)) return 1;
	}
	return 0;
}

bool dfsb(int ver){
	//cout<<"dfsb "<<ver<<endl;
	if(visb[ver])return 0;
	visb[ver]=1;
	REP(i,vb[ver].size()){
		int nver = vb[ver][i].first;
		int nval = b[ver] ^ vb[ver][i].second;
		if(a[nver]!=-1 && a[nver]!=nval){
			return 1;
		}
		if(a[nver]!=-1)continue;
		a[nver]=nval;
		if(dfsa(nver)) return 1;
	}
	return 0;
}

int solve(string s){
	if(s.back()=='1')return 0;

	ll res = 0;
	int n = s.size();
	FOR(len,1,n){
		//cout<<"start "<<len<<endl;
		CL(b,-1);CL(a,-1);
		CL(visa,0),CL(visb,0);
		REP(i,n)va[i].clear(),vb[i].clear();
		bool shit=0;
		FOR(i,1,n-1){
			if(s[i]=='?')continue;
			int v = s[i]-'0';
			int bi = min(i,n-1-i)-1;
			if(i==n-len)v^=1;
			
			if(i>n-len){
				int ai=i-(n-len+1)+1;
				ai=min(ai,len-1-ai);
				ai--;
				//cout<<bi<<' '<<ai<<endl;
				if(!vb[bi].empty() && vb[bi].back().first==ai){
					if(vb[bi].back().second!=v){shit=1;break;}
				}else vb[bi].pb(pii(ai,v));

				if(!va[ai].empty() && va[ai].back().first==bi){
					if(va[ai].back().second!=v){shit=1;break;}
				}else va[ai].pb(pii(bi,v));
			}else{
				if(b[bi]!=-1 && b[bi]!=v){shit=1;break;}
				b[bi]=v;
			}
		}
		if(shit)continue;
		REP(i,(n+1)/2-1)if(b[i]!=-1){
			shit|=dfsb(i);
			if(shit)break;
		}
		if(shit)continue;
		//REP(i,(n+1)/2-1)cout<<b[i]<<' ';puts("");
		//REP(i,(len+1)/2-1)cout<<a[i]<<' ';puts("");
		//cout<<"vb "<<vb[0].size()<<endl;
		int var=0;
		REP(i,(n+1)/2-1)if(b[i]==-1)var++,var-=vb[i].size();
		REP(i,(len+1)/2-1)if(a[i]==-1)var++;

		//cout<<var<<' '<<len<<endl;
		if(var<0)cout<<"FUCK " <<var<<' '<<len<<endl;
		else res=(res+qp(2,var))%mod;
	}
	return res;
}

bool isp(int a){
	vi v;
	while(a){
		v.pb(a%2);
		a/=2;
	}
	REP(i,v.size())if(v[i]!=v[v.size()-1-i])return 0;
	return 1;
}
bool good(string s,int c){
	REP(i,s.size()){
		int v =c%2;
		c/=2;
		if(s[s.size()-1-i]=='?')continue;
		if(s[s.size()-1-i]-'0'!=v)return 0;
	}
	return 1;
}

int stupid(string s){
	int n = s.size();
	int res=0;
	FOR(a,1,1<<n)if(isp(a))FOR(b,a+1,1<<n)if(isp(b)){
		int c=a^b;
		if(good(s,c)){
			//cout<<"g: "<<a<<' '<<b<<endl;
			res++;
		}
	}
	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	string s;
	cin>>s;
	cout<<solve(s)<<endl;




#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}