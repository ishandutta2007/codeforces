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

vector<pii> v1,v2;
int n,v;


set<int> s;

int main(){
#ifdef LocalHost    
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
#endif

	cin>>n>>v;
	REP(i,n){
		int x,y;
		scanf("%d %d",&x,&y);
		if(x==1) v1.pb(pii(y, i+1));
		else     v2.pb(pii(y, i+1));
	}
	SORT(v1),SORT(v2);
	int pos = 0;
	while(v1.size() - pos > v) pos++;

	int sum = 0;
	FOR(i,pos,v1.size()) sum += v1[i].first,s.insert(v1[i].second);
	int num = v1.size() - pos;

	int pos2 = v2.size();
	while(pos2 > 0 && num + 2 <= v) num+=2,pos2--,sum += v2[pos2].first, s.insert(v2[pos2].second);

	if(num+1 == v && pos2>0 && pos < v1.size() && v2[pos2-1].first > v1[pos].first){
		num++;
		pos++;
		pos2--;
		sum -= v1[pos-1].first;
		sum += v2[pos2].first;
		s.erase(v1[pos-1].second);
		s.insert(v2[pos2].second);
	}

	while(num==v && pos2>0 && pos + 1 < v1.size() && v2[pos2-1].first > v1[pos].first + v1[pos+1].first){
		sum -= v1[pos].first;
		sum -= v1[pos+1].first;
		s.erase(v1[pos].second);
		s.erase(v1[pos+1].second);
		pos+=2;
		pos2 --;
		sum += v2[pos2].first;
		s.insert(v2[pos2].second);

	}

	cout<<sum<<endl;
	bool f = 1;
	for(set<int>::iterator it = s.begin(); it!=s.end();it++){
		if(!f) printf(" ");
		f=0;printf("%d",*it);
	}
	puts("");

	return 0;
}