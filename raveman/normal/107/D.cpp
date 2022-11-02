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

const int mod = 12345;
const int M2 = mod * mod;

ll n;
int c;
int t[1111],k[1111];
vi v[26];
int g[26];
int G;

struct M{
	int a[123][123];
	M(){CL(a,0);}
	M pow(M &s){
		M r;
		REP(i,123)REP(j,123){
			int x = 0;
			REP(k,123){
				x += a[i][k] * s.a[k][j];
				if(x>=M2) x-=M2;
			}
			r.a[i][j] = x%mod;
		}
		return r;
	}
};

int gcd(int a,int b){
	while(a&&b)
		if(a>b) a%=b;
		else b%=a;
	return a+b;
}

M qp(M m,ll n){
	M t;
	REP(i,123) t.a[i][i] = 1;
	while(n){
		if(n&1) t = t.pow(m);
		m = m.pow(m);
		n>>=1;
	}
	return t;
}

bool good(int i){
	vi t(26);
	int curr = i;
	REP(j,26)if(g[j]){
		t[j] = curr % g[j];
		curr /= g[j];
	}
	REP(j,26)if(g[j]){
		bool f = 0;
		REP(k,v[j].size())
			if(t[j] % v[j][k]==0){f=1;break;}
		if(!f) return 0;
	}
	return 1;
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
	cin>>c;
	REP(i,c){
		char T;
		scanf(" %c %d",&T,&k[i]);
		t[i] = T-'A';
		v[t[i]].pb(k[i]);

		
	}
	G = 1;
	REP(i,26){
		UN(v[i]);
		if(v[i].size()){
			g[i] = v[i][0];
			REP(j,v[i].size())
				g[i] = g[i] * v[i][j] / gcd(g[i], v[i][j]);
			G *= g[i];
		}
	}
	M m;
	REP(i,G){
		vi t(26);
		int curr = i;
		REP(j,26)if(g[j]){
			t[j] = curr % g[j];
			curr /= g[j];
		}
		
		REP(j,26)if(g[j]){
			t[j] ++;
			if(t[j] >= g[j]) t[j] = 0;

			int val = 0;
			for(int q=25;q>=0;q--) if(g[q]){
				val = val * g[q] + t[q];
			}
			m.a[i][val] ++;

			t[j] --;
			if(t[j]<0) t[j] += g[j];
		}
	}

	m = qp(m,n);

	int res = 0;
	REP(i,G){
		int val = m.a[i][0];
		if(good(i)){
			res += val;
			res %= mod;
		}
	}
	cout<<res<<endl;
	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}