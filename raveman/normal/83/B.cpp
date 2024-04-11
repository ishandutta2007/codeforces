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

ll k;
int n;
int a[111111];
pii p[111111];

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	REP(i,n){
		scanf("%d",a+i),p[i]=pii(a[i],i);
	}
	sort(p,p+n);
	if(k==0){
		REP(i,n){
			if(i)printf(" ");
			printf("%d",i+1);
		}
		return 0;
	}
	ll num = 0;
	int pos = -1;
	ll prev;
	int num_prev;
	REP(i,n){
		int q = n - i;
		prev = num;
		num += (p[i].first - (i?p[i-1].first:0)) * ll(q);
		num_prev = (i?p[i-1].first:0);
		if(num > k){
			pos = p[i].first;
			break;
		}
	}
	if(num==k){
		puts("");
		return 0;
	}

	if(num<k){
		puts("-1");
		return 0;
	}

	k-=prev;
	vector<pii> v;
	REP(i,n) if(a[i]>=pos) v.pb(pii(a[i]-num_prev,i));

	int c = k / v.size();
	REP(i,v.size()) v[i].first -= c;

	k %= v.size();

	pos = k;
	bool f=1;
	REP(i,pos) v[i].first--;
	for(int i=pos;i<pos+v.size();i++) if(v[i%v.size()].first>0){
		if(!f) printf(" ");
		f=0;
		printf("%d",v[i%v.size()].second+1);
	}
	puts("");	

	return 0;
}