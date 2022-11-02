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

const int mod = 1000000009;
int n,m;
vector<string> v;

string D = "ACGT";
map<vi,int> c[1001];

int R1[11][11][11];
int next(int pos,int len,int next){
	if(R1[pos][len][next]!=-1) return R1[pos][len][next];
	string s = v[pos].substr(0, len);
	s += D[next];
	while(v[pos].substr(0, s.size()) != s)
		s.erase(s.begin());
	return R1[pos][len][next]=s.size();
}
int R2[11];
int pref(int pos){
	if(R2[pos]!=-1) return R2[pos];
	string s = v[pos];
	s.erase(s.begin());
	while(v[pos].substr(0, s.size()) != s)
		s.erase(s.begin());
	return R2[pos]=s.size();
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	CL(R2,-1);
	CL(R1,-1);

	cin>>n>>m;
	REP(i,m){
		string s;
		cin>>s;
		v.pb(s);
	}
	UN(v);
	vi t(v.size()+1);
	t[t.size()-1] = (1<<9)-1;
	c[0][t]=1;
	for(int i=0;i<n;i++){
		//cout<<c[i].size()<<endl;
		for(map<vi,int>::iterator it = c[i].begin();it!=c[i].end();it++){
			t = it->first;
			int val = it->second;
			int mask = t.back();
			t.pop_back();

			REP(j,4){
				vi nv(v.size()+1);
				int nmask = mask<<1;
				int mx=0;
				REP(k,v.size()){
					nv[k] = next(k,t[k],j);
					if(nv[k] == v[k].size()){
						nmask |= ((1<<nv[k])-1);
						nv[k] = pref(k);
					}
					mx=max(mx,nv[k]);
				}
				if(nmask&(1<<9)){}
				else continue;

				int pos = 9;
				while(pos>=0 && (nmask&(1<<pos))) pos--;
				if(pos>=mx) continue;
				for(int www=pos;www>=0;www--)
					if(nmask&(1<<www))
						nmask^=(1<<www);
				// calcmask

				nv.pb(nmask^(1<<9));
				int q = c[i+1][nv];
				q += val;
				if(q>=mod) q-=mod;
				c[i+1][nv] = q;

			}
		}
	}
	int res = 0;
	for(map<vi,int>::iterator it = c[n].begin();it!=c[n].end();it++){
		t = it->first;
		int val = it->second;
		int mask = t.back();
		t.pop_back();

		if(mask == (1<<9) - 1){
			res += val;
			if(res>=mod) res-=mod;
		}
	}
	cout<<res<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<clock()<<endl;
#endif
	return 0;
}