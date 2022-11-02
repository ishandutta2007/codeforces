#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
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
p3i a[211111];
vector<p3i> v;
vi r;
int main(){
//    freopen("input.txt","r",stdin);
	int TC;
	cin>>TC;
	REP(tc,TC){
		scanf("%d",&n);
		n=2*n-1;
		REP(i,n) scanf("%d %d",&a[i].first.first,&a[i].first.second),a[i].second=i;
		sort(a,a+n);
		v.clear();r.clear();
		REP(i,n){
			if(v.size() && v.back().first.second <= a[i].first.second){
				r.pb(a[i].second);
				v.pop_back();
			}else v.pb(a[i]);
		}
		for(int i=0;i<v.size();i+=2)
			r.pb(v[i].second);

		SORT(r);
		puts("YES");
		REP(i,r.size()){
			if(i) printf(" ");
			printf("%d",r[i]+1);
		}
		puts("");
	}
    return 0;
}