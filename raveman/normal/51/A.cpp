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

set<int> m;
int n;

int main(){
#ifdef LocalHost    
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	cin>>n;
	REP(i,n){
		char c1,c2,c3,c4;
		if(i) scanf(" %c%c",&c1,&c2);
		scanf(" %c%c",&c1,&c2);
		scanf(" %c%c",&c3,&c4);

		int d = 9999;
		REP(q,4){
			swap(c1,c3);
			swap(c2,c1);
			swap(c4,c2);
			d=min(d,1000*(c1-'0')+100*(c2-'0')+10*(c3-'0')+c4-'0');
		}
		m.insert(d);
	}
	cout<<m.size()<<endl;
	return 0;
}