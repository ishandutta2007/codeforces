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

char s[1111111];
int  n;
int main(){
#ifdef LocalHost

    freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
#endif
	
	gets(s);
	n = strlen(s);
	ll rrr=0;
	REP(i,n) rrr=rrr*2+(s[i]-'0');

	vector<pii> r;
	vector<pii> v;
	int res = 0;
	REP(i,n){
		int dig = s[i]-'0';
		if(v.size() && v.back().first==dig) v.back().second++;
		else v.pb(pii(dig,1));
	}
	vector<pii> w;
	swap(v,w);

	int sm=0;
	REP(i,w.size()){
		pii curr = w[i];
		sm += curr.second;
		if(v.size() && v.back().first==0 && v.back().second==1 && (curr.second>1 || v.size()>1 && v[v.size()-2].second>1)){
			v.pop_back();
			v.back().second++;
			v.back().second+=curr.second;
			r.pb(pii(0,n-(sm-curr.second)));
		}else v.pb(curr);
	}

	int sum=0;
	REP(i,v.size()){
		if(v[i].first==1){
			if(v[i].second==1){
				r.pb(pii(1,n-sum-1));
			}else{
				r.pb(pii(1,n-sum));
				r.pb(pii(0,n-sum-v[i].second));
			}
		}
		sum += v[i].second;
	}
	cout<<r.size()<<endl;
	ll t = 0;
	REP(i,r.size()){
		//if(r[i].first) t += 1ll<<r[i].second;
		//else t-=1ll<<r[i].second;
		printf("%c2^%d\n",r[i].first?'+':'-',r[i].second);
	}

	
#ifdef LocalHost
    cout<<rrr<<' '<<t<<endl;
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}