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

set<pii> s;
int n,k;
pii p[222222];
pii a[22];
int pos;

int solve1(){
	REP(i,1<<n){
		int nb = 0;
		pos=0;
		REP(j,n) if(i&(1<<j)) nb++;
		else a[pos++]=p[j];
		if(nb<=k){
			bool good = true;
			int s1 = a[0].first+a[pos-1].first;
			int s2 = a[0].second+a[pos-1].second;
			FOR(j,1,pos/2+1)
				if(a[j].first+a[pos-j-1].first!=s1 || a[j].second+a[pos-j-1].second!=s2) {good=0;break;}
			if(good) s.insert(pii(s1,s2));
			//else puts("fuck");
		}
	}
	return s.size();
}

int solve2(){
	s.clear();
	REP(i,k+1) REP(j,k+1){
		int s1 = p[i].first + p[n-1-j].first;
		int s2 = p[i].second + p[n-1-j].second;

		int num = 0;
		int p1 = 0;
		int p2 = n-1;
		while(p1<=p2){
			if(p1==p2){
				if(p[p1].first*2 == s1 && p[p1].second*2 == s2) num++;
				break;
			}else{
				if(p[p1].first+p[p2].first==s1 && p[p1].second + p[p2].second==s2){num+=2;p1++;p2--;continue;}
				if(p[p1].first+p[p2].first>s1){p2--;continue;}
				if(p[p1].first+p[p2].first<s1){p1++;continue;}
				if(p[p1].second+p[p2].second>s2){p2--;continue;}
				if(p[p1].second+p[p2].second<s2){p1++;continue;}
				//puts("fucj");
			}
		}
		if(num+k>=n) s.insert(pii(s1,s2));
		//cout<<i<<' '<<j<<' '<<num+k<<' '<<n<<' '<<s.size()<<endl;
	}
	//cout<<"ret "<<s.size()<<endl;
	return s.size();
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
#endif

//start:
	cin>>n>>k;
	//n=rand()%4+1;
//	k=rand()%4;
	if(n<=k){
		puts("-1");
	//	goto start;
	}else{
		REP(i,n) scanf("%d %d",&p[i].first,&p[i].second);		
		sort(p,p+n);

		if(0)while(solve1()!=solve2()){
			cout<<solve1()<<' '<<solve2()<<endl;//puts("FUCK");
			cout<<n<<' '<<k<<endl;
			REP(i,n) cout<<p[i].first<<' '<<p[i].second<<endl;
			return 0;
		}

		if(2*k>=n){
			solve1();
		}else{
			solve2();
		}
		//goto start;
		cout<<s.size()<<endl;
		for(set<pii>::iterator it = s.begin();it!=s.end();it++){
			pii x = *it;
			printf("%.1lf %.1lf\n",x.first/2.,x.second/2.);
		}
	}
	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}