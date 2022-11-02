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

int n;
int a[555555],b[555555],c[555555];

struct w {
	int a,b,c;
	w(){}
	bool operator<(const w&s)const{return a>s.a;}
};

w g[555555];

set<pii> s;

void add(int a,int b){
	while(s.size()){
		set<pii>::iterator it  = s.lower_bound(pii(a,b));
		if(it!=s.end() && (*it).first >= a && (*it).second>=b) return;
		if(it!=s.begin()){
			it--;
			pii val = *it;
			if(val.first <= a && val.second<=b){
				s.erase(it);
			}else break;
		}else break;

	}
	s.insert(pii(a,b));
}

bool bad(int a,int b){
	set<pii>::iterator it  = s.lower_bound(pii(a+1,b+1));
	if(it == s.end()) return 0;
	pii val = *it;
	if(val.first > a && val.second > b) return 1;
	return 0;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
 ///   freopen("output.txt","w",stdout);
#endif
	cin>>n;
	REP(i,n) scanf("%d",a+i);
	REP(i,n) scanf("%d",b+i);
	REP(i,n) scanf("%d",c+i);
	REP(i,n) g[i].a = a[i],g[i].b =b[i],g[i].c=c[i];

	sort(g,g+n);

	int res = 0;
	for(int i=0;i<n;){
		int j = i;
		while(j<n && g[i].a == g[j].a) j++;


		FOR(k, i, j)			if(bad(g[k].b, g[k].c)) res++,g[k].a=-1;
		FOR(k, i, j) if(g[k].a!=-1) add(g[k].b, g[k].c);
		i=j;
	}
	cout<<res<<endl;

    return 0;
}