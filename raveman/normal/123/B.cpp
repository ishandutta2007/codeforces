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

int a,b,x,y,X,Y;

pii convert(int x,int y){
	return pii(x+y,x-y);
}

int convert3(int x,int a){
	if(x>0) return x/(2*a);
	return x/(2*a)-1;
}
pii convert2(pii t){
	
	return pii(convert3(t.first,a),convert3(t.second,b));
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>a>>b>>x>>y>>X>>Y;

	pii t1 = convert(x,y);
	pii t2 = convert(X,Y);
	t1 = convert2(t1);
	t2 = convert2(t2);
	cout<<max(abs(t1.first-t2.first),abs(t1.second-t2.second))<<endl;
	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}