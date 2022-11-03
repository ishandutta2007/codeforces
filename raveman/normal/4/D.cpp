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

p3i p[5555];
int n;
int d[5555];
int f[5555];

int main(){
#ifdef LocalHost    
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
#endif

	int n,h,w;
	cin>>n>>w>>h;
	REP(i,n) scanf("%d %d",&p[i].first.first,&p[i].first.second),p[i].second = i + 1;
	sort(p,p+n);
	int mx = -1;
	REP(i,n) if(p[i].first.first > w && p[i].first.second > h){
		d[i] = 1;
		f[i] = -1;

		REP(j,i) if(d[j]+1 > d[i] && p[i].first.first > p[j].first.first && p[i].first.second > p[j].first.second){
			d[i] = d[j]+1;
			f[i] = j;
		}
		if(mx==-1 || d[mx] < d[i]) mx = i;
	}
	if(mx==-1) puts("0");
	else{
		cout<<d[mx]<<endl;
		vi res;
		while(mx>=0){
			res.pb(p[mx].second);
			mx = f[mx];
		}
		reverse(res.begin(),res.end());
		REP(i,res.size()){
			if(i) printf(" ");
			printf("%d",res[i]);
		}
		puts("");
	}
	return 0;
}