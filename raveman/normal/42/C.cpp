#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include<complex>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int a[4];

vector<pii> res;


void make1(){
	while(a[0]!=1){
		if(a[0]%2==0 && a[1]%2==0){
			res.pb(pii(0,1));
			a[0]/=2;
			a[1]/=2;
		}else if(a[0]%2==0){
			res.pb(pii(1,2));
			a[1]++;
			a[2]++;
			res.pb(pii(0,1));
			a[0]/=2;
			a[1]/=2;				
		}else if(a[1]%2){
			res.pb(pii(1,1));
			a[0]++;
			a[1]++;
		}else{
			res.pb(pii(1,4));
			a[0]++;
			a[3]++;
		}
	}
}

void make2(){
	while(a[1]!=1){
		if(a[1]%2==0 && a[2]%2==0){
			res.pb(pii(0,2));
			a[1]/=2;
			a[2]/=2;
		}else if(a[1]%2==0){
			res.pb(pii(1,3));
			a[2]++;
			a[3]++;
			res.pb(pii(0,2));
			a[1]/=2;
			a[2]/=2;				
		}else{
			res.pb(pii(1,1));
			a[0]++;
			a[1]++;
			res.pb(pii(0,1));
			a[0]/=2;
			a[1]/=2;
		}
	}
}
void make3(){
	while(a[2]!=1){
		if(a[2]%2==0 && a[3]%2==0){
			res.pb(pii(0,3));
			a[2]/=2;
			a[3]/=2;
		}else if(a[2]%2==0){
			res.pb(pii(1,3));
			a[2]++;
			a[3]++;
			res.pb(pii(1,2));
			a[1]++;
			a[2]++;
			res.pb(pii(0,2));
			a[1]/=2;
			a[2]/=2;				
		}else{
			res.pb(pii(1,2));
			a[1]++;
			a[2]++;
			res.pb(pii(0,2));
			a[1]/=2;
			a[2]/=2;
		}
	}
}

void make4(){
	while(a[3]!=1){
		if(a[3]%2){
			res.pb(pii(1,3));
			a[2]++;
			a[3]++;
			res.pb(pii(0,3));
			a[2]/=2;
			a[3]/=2;
		}else{
			res.pb(pii(1,4));
			res.pb(pii(1,3));
			a[2]++;a[3]++;
			a[3]++;a[0]++;
			res.pb(pii(0,3));
			a[2]/=2;a[3]/=2;
			if(a[3]%2==0){
				res.pb(pii(0,4));
				a[3]/=2;
				a[0]/=2;
			}else{
				while(a[3]&1){
					res.pb(pii(1,3));
					a[2]++;
					a[3]++;
					res.pb(pii(0,3));
					a[2]/=2;
					a[3]/=2;
				}
				res.pb(pii(0,4));
				a[3]/=2;
				a[0]/=2;
			}
		}
	}
}

int main(){
#ifdef LocalHost    
	freopen("input.txt","r",stdin);
#endif

	REP(i,4) cin>>a[i];

	

	make1();
	make2();
	make3();
	make4();

	//P(i,4) cout<<a[i]<<' ';puts("");


	REP(i,res.size()){
		if(res[i].first==0) printf("/%d\n",res[i].second);
		else printf("+%d\n",res[i].second);
	}

	return 0;
}