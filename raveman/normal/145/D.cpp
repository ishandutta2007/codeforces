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

int n;
int a[111111];
vi v;

bool lucky(int x){
	while(x){
		int c = x%10;
		if(c!=4 && c!=7) return 0;
		x/=10;
	}
	return 1;
}

map<int,vi> pos;
set<int> cannot;

int stupid(){
	int res = 0;
	REP(i,n){
		cannot.clear();
		FOR(j,i,n){
			if(lucky(a[j])) cannot.insert(a[j]);
			FOR(x,j+1,n){
				FOR(z,x,n){
					if(lucky(a[z]) && cannot.count(a[z])) break;
					res++;
				}
			}
		}
	}
	return res;
}
set<int> parsed;
bool DEBUG=0;

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n) scanf("%d",a+i);

	REP(i,n)
		if(lucky(a[i])) v.pb(a[i]),pos[a[i]].pb(i);
		else{
			if(v.size() && v.back()<0) v.back()--;
			else v.pb(-1);
		}
	ll res = 0;
	int rpos = 0;
	REP(i,v.size()){		
		cannot.clear();
		int nextpos = rpos;
		if(v[i]<0) nextpos -= v[i];
		else nextpos++;

		int tpos = rpos;
		parsed.clear();
		ll cnt = (n-nextpos)*ll(n-nextpos+1)/2;
		for(int j=i;j<v.size();j++){

			int rnextpos = tpos;
			if(v[j]<0) rnextpos -= v[j];
			else rnextpos ++;
			
			if(v[j]>0){

				if(cannot.count(tpos))
					cannot.erase(tpos);
				if(!parsed.count(v[j])){
					parsed.insert(v[j]);
					vi &vv = pos[v[j]];
					for(int k=vv.size()-1;vv[k]>=rnextpos;k--){

						cannot.insert(vv[k]);
						set<int>::iterator it = cannot.find(vv[k]);
						set<int>::iterator it2 = it;
						ll end = n;
						it2++;
						if(it2!=cannot.end()) end = *it2;
						ll beg = rnextpos-1;
						if(it!=cannot.begin()){
							it--;
							beg = *it;
						}
						ll len = end - beg - 1;

						cnt -= len*(len+1)/2;
						cnt += (end-vv[k]-1)*(end-vv[k])/2;
						cnt += (vv[k]-beg-1)*(vv[k]-beg)/2;
					}
				}
			}
			ll c1 = -v[i];if(c1<0) c1=1;
			ll c2 = -v[j];if(c2<0) c2=1;
			if(i==j){
				res += c1*(c1+1)/2*cnt;
					
			}else{
				res += c1*c2*cnt;
					
			}
			if(c2>1){
				if(i==j){
					res += c1*(c1-1)/2;
					res += c1*(c1-1)*(c1-2)/3;
					ll t = c1*(c1-1)/2*(c1-2)/3;
					ll t2 = (c1-3);
					if(t%4==0) t/=4;
					else if(t2%4==0) t2/=4;
					else t/=2,t2/=2;
					res += t*t2;
					int val = n;
					if(cannot.size()) val = *cannot.begin();
					res += c1 *(c1-1) / 2 *(val - rnextpos);
					res += c1 * (c1-1)*(c1-2)/6*(val - rnextpos);
				}else{
					res += c1*c2*(c2-1)/2;
					ll t = c1*c2*(c2-1)/2;
					ll t2 = (c2-2);
					if(t%3==0) t/=3;
					else t2/=3;
					res += t*t2;

					int val = n;
					if(cannot.size()) val = *cannot.begin();
					res += c1 * c2*(c2-1)/2*(val - rnextpos);
				}
			}
			if(j+1<n){
				int val = n;
				if(cannot.size()) val = *cannot.begin();
				ll nm = -v[j+1];
				if(nm<0) nm = 1;
				cnt -= (val-rnextpos+val-rnextpos-nm+1)*nm/2;
				tpos=rnextpos;
			}
		}
		rpos = nextpos;
	}
	cout<<res<<endl;//' '<<stupid()<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}