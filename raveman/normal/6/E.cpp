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

int n,k;
int a[111111];

int r;
vector<pii> res;
map<int,int> s;
map<int,int>::iterator it;
int x,y;

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
 ///   freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	while(n>100000);
	//k=0;
	//n=100000;
	REP(i,n) scanf("%d",a+i);
	//REP(i,n) a[i]=i;
	r=0;
	//s[a[0]]=1;
	int p1=0,p2=0;
	while(p2<n){
		//while(res.size()>100000 || s.size()>100000);
		//cout<<p1<<' '<<p2<<endl;
		if(s.size()==0) s[a[p2]]++,p2++;
		while(p2<n){
			x = min(s.begin()->first,a[p2]);
			it = s.end();it--;
			y = max(it->first,a[p2]);
			//cout<<x<<' '<<y<<endl;		
			if(y-x<=k) s[a[p2]]++,p2++;
			else break;
		}
		if(p2-p1 > r) r=p2-p1,res.clear();
		if(p2-p1==r) res.pb(pii(p1+1,p2));
		if(--s[a[p1]] == 0)
			s.erase(a[p1]);
		p1++;
		
	}

	cout<<r<<' '<<res.size()<<endl;
	REP(i,res.size()) printf("%d %d\n",res[i].first,res[i].second);
//	while(1);
	return 0;
}