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
int best = 7;
set<ll> been[10];

typedef pair<pii,pii> p4;

p4 a[10];
p4 b[10];

void go(vi v,int num=0){
	if(num >= best) return;
	if(v.back()>n) return;
	if(v.back()==n){
		if(best > num){
			best = num;
			REP(i,num) b[i]=a[i];
		}
	}
	
	ll hash = 0;
	REP(i,v.size()) hash = hash*10007 + v[i];
	if(been[num].count(hash)) return;
	been[num].insert(hash);
	
	vi t=v;
	UN(t);
	if(t!=v) return;

	REP(i,v.size()) REP(j,v.size()){
		t = v;
		t.pb(v[i]+v[j]);
		vi q = t;
		SORT(q);
		if(q!=t) continue;
		a[num] = p4(pii(0,0),pii(i,j));
		go(t,num+1);
	}
	REP(i,v.size()) for(int k=1;k<=8;k*=2){
		t = v;
		t.pb(v[i]*k);

		vi q = t;
		SORT(q);
		if(q!=t) continue;
		
		a[num] = p4(pii(1,k),pii(i,i));
		go(t,num+1);
	}
	REP(i,v.size()) REP(j,v.size())for(int k=2;k<=8;k*=2){
		t = v;
		t.pb(v[i]+v[j]*k);
		
		vi q = t;
		SORT(q);
		if(q!=t) continue;
		
		a[num] = p4(pii(2,k),pii(i,j));
		go(t,num+1);
	}

}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);w
#endif

	cin>>n;
	//for(n=1;n<=255;n++){
		best=7;
		REP(i,10) been[i].clear();

		vi c(1,1);
		go(c);

		//if(best==7) while(1) puts("FICK");
		//cout<<n<<endl;
		cout<<best<<endl;
		REP(i,best){
			if(b[i].first.first==0){
				cout<<"lea e"<<char('a'+i+1)<<"x, [e"<<char('a'+b[i].second.first)<<"x + e"<<char('a'+b[i].second.second)<<"x]"<<endl;
			}else if(b[i].first.first==1){
				cout<<"lea e"<<char('a'+i+1)<<"x, ["<<b[i].first.second<<"*e"<<char('a'+b[i].second.first)<<"x]"<<endl;
			}else{
				cout<<"lea e"<<char('a'+i+1)<<"x, [e"<<char('a'+b[i].second.first)<<"x + "<<b[i].first.second<<"*e"<<char('a'+b[i].second.second)<<"x]"<<endl;
			}
		}
	//}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}