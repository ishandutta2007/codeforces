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
typedef pair<pii,int> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int d[22][22][4][4];

int go(int n,int h,int l1,int l2){
	if(h<0) return 0;
	if(n==2){
		if(l1>l2) return 0;
		return h==0 ? 1 : 0;
	}
	int &val = d[n][h][l1][l2];
	if(val!=-1) return val;
	val=0;
	REP(l0,4)if(l0!=l1)
		val += go(n-1,h+(l1>l0 && l1>l2 ? -1 : 0),l0,l1);
	return val;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	CL(d,-1);

	int n,t;
	cin>>n>>t;
	int sum = 0;
	REP(l1,4)REP(l2,4)if(l1>l2)
		sum += go(n,t,l1,l2);
	cout<<sum<<endl;
	
	return 0;
}