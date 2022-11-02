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

const int mod = 1000000007;

int ten[1111];

int qp(int __un, int st){
	if(ten[0]==-1){
		ten[0] = 1;
		FOR(i,1,1111){
			ten[i] = (10ll * ten[i-1])% mod;
		}
	}
	return ten[st];
}

int t,k;
char s1[1111];
char s2[1111];

int d[1111][1111];

int go(int n,int w){
	if(n==0) return 0;
	w = min(w, k);
	//cout<<n<<' '<<w<<endl;
	if(d[n][w]!=-1) return d[n][w];
	
	ll res = 0;
	res += 8ll * go(n-1,w+1);
	if(w+1<=k) res += 2 * qp(10,n-1);//ten[n-1];
	else res += 2 * go(n-1,0);
	res %= mod;
	//cout<<n<<' '<<w<<' '<<res<<endl;
	return d[n][w] = res;
}

int solve(char *s){
	int  res = 0;
	
	int n = strlen(s);
	int last = -1000000;
	bool calcf = 1;
	REP(i,n){
		REP(d,s[i]-'0'){
			if((d==7 || d==4) && i-last<=k){
				res += qp(10, n-1-i);
				if(res>=mod) res-=mod;
			}else if((d==7 || d==4)){
				res += go(n-i-1, 0);
				if(res>=mod) res-=mod;
			}else{
				res += go(n-i-1,i-last);
				if(res>=mod) res-=mod;
			}
		}

		if(s[i]=='4' || s[i]=='7'){
			if(i-last<=k){
				ll t = 0;
				FOR(j,i+1,n){
					t = 10 * t + s[j] - '0';
					t %= mod;
				}
				t++;

				res += t;
				res%= mod;
				return res;
			}
			last = i;
		}
		
	}
	
	return res;
}

char TT[1111];

bool good(char *s){
	int n = strlen(s);
	int last = -1000000;
	REP(i,n) if(s[i]=='4' || s[i]=='7'){
		if(i-last<=k) return 1;
		last = i;
	}
	return 0;
}

int stupid(){
	string _s1(s1);
	string _s2(s2);
	stringstream ss1(_s1);
	stringstream ss2(_s2);
	int l,r;
	ss1>>l;
	ss2>>r;
	int res =0 ;
	for(int i=l;i<=r;i++){
		stringstream ss;
		ss<<i;
		string w = ss.str();
		REP(j,w.size()) TT[j] = w[j];
		TT[w.size()]=0;
		if(good(TT)) res++;
	}
	return res;
}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	CL(d,-1);CL(ten,-1);
	cin>>t>>k;

	if(0){FOR(i,445,1000){
		FOR(j,max(1,i-100),i+1){
			stringstream ss1,ss2;
			ss1<<j;ss2<<i;
			string  _s1 = ss1.str();
			string _s2 = ss2.str();
			REP(k,_s1.size()) s1[k] = _s1[k];
			s1[_s1.size()] = 0;
			REP(k,_s2.size()) s2[k] = _s2[k];
			s2[_s2.size()] = 0;

			int res = solve(s2);
			res -= solve(s1);
			if(good(s1)) res++;
			if(res>=mod) res-=mod;
			if(res<0) res += mod;
			if(res!=stupid())
				puts("ok!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			//else cout<<j<<endl;
			//cout<<res<<endl;//	' '<<stupid()<<endl;
		}
		cout<<i<<endl;
	}
	puts("DONE!");
	}
	REP(i,t){
		scanf(" %s %s",s1,s2);
		int res = solve(s2);
		//cout<<s2<<' '<<solve(s2)<<endl;
		//cout<<s1<<' '<<solve(s1)<<endl;
		res -= solve(s1);
		if(good(s1)) res++;
		if(res>=mod) res-=mod;
		if(res<0) res += mod;
		cout<<res<<endl;//	' '<<stupid()<<endl;
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}