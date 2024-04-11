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

vi p;
int a,b,k;
int res;
int A,B;

void go(int k,bool par,int pos){
	if(pos==p.size()){
		int val = (B/k - (A-1)/k);
		if(par) res -= val;
		else res += val;
	}else{
		if(k*ll(p[pos]) <= B)
			go(k*p[pos],!par,pos+1);
		go(k,par,pos+1);
	}
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>a>>b>>k;
	bool isP=1;
	for(int j=2;j*ll(j)<=k;j++)if(k%j==0){isP=0;break;}
	if(!isP){
		puts("0");
		return 0;
	}
	for(int i=2;i<k;i++){
		bool pr = 1;
		for(int j=2;j*j<=i;j++)if(i%j==0){pr=0;break;}
		if(pr) p.pb(i);
		if(p.size() > 5005) break;
	}
	A=(a-1)/k;A++;
	B=b/k;
	//cout<<p.back()<<endl;
	if(p.size() > 5005){
		//puts("1");
		for(int v=A;v<=B;v++){
			if(v>1 && v<k) continue;			
			bool g = 1;
			for(int j=2;j*j<=v && j<k;j++) if(v%j==0) {g=0;break;}
			if(g) res++;
		}
	}else{
		//puts("2");
		go(1,0,0);
	}
	//cout<<clock()<<endl;
	cout<<res<<endl;
	return 0;
}