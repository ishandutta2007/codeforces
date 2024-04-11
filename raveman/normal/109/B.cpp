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

vi v;

void gen(ll c){
	if(c>=1000000000)return;
	if(c) v.pb(c);
	gen(c*10+4);
	gen(c*10+7);
}

ll inter(ll x,ll X,ll y,ll Y){
	ll a = max(x,y);
	ll b = min(X,Y);
	if(a<=b)return b-a+1;
	return 0;
}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif
#ifndef LocalHost
	//freopen("dices.in","r",stdin);
	//freopen("dices.out","w",stdout);
#endif

	gen(0);
	SORT(v);
	int a,A,b,B,k;
	cin>>a>>A>>b>>B>>k;
	ll num1 = 0;
	ll num2 = ll(A-a+1)*ll(B-b+1);
	REP(i,v.size()){
		int j = i + k - 1;
		if(j>=v.size()) continue;

		int beg = (i?v[i-1]+1:1);
		int end = (j+1<v.size()?v[j+1]-1:1000000000);

		num1 += inter(beg,v[i],a,A)  * inter(v[j],end,b,B);
		num1 += inter(beg,v[i],b,B)  * inter(v[j],end,a,A);

		if(k==1 && v[i]>=a && v[i]<=A && v[i]>=b && v[i]<=B) num1--;

	}
	printf("%.10lf\n",double(num1)/num2);

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}