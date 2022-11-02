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
int x[211111];
int y[211111];

bool sq(int i,int j,ll X,ll Y){
	return (x[i]-X)*(y[j]-Y)-(x[j]-X)*(y[i]-Y)<=0;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
 ///   freopen("output.txt","w",stdout);
#endif
	cin>>n;
	REP(i,n) scanf("%d %d",x+i,y+i),x[i+n]=x[i],y[i+n]=y[i];
	int tc;
	cin>>tc;
	REP(TC,tc){
		ll X,Y;
		cin>>X>>Y;

		ll t = 0,t2=0;
		REP(i,n){
			ll v = (x[i]-X) * (y[i+1]-Y) - (x[i+1]-X) * (y[i]-Y);
			if(v<0) v=-v;
			t+=v;

			v = (x[i]-x[0]) * ll(y[i+1]-y[0]) - (x[i+1]-x[0]) * ll(y[i]-y[0]);
			if(v<0) v=-v;
			t2+=v;
		}
		if(t!=t2){
			cout<<0<<endl;
			continue;
		}

		ll res = ll(n) * ll(n-1) * ll(n-2);
		res/=6;

		ll sub = 0;

		int p1 = 0;
		REP(i,n){
			while(sq(i,p1,X,Y)) p1++;
			p1--;

			int num = p1 - i;
			if(num>=2) 
				sub += ll(num) * (num - 1) /2;
		}

		cout<<res - sub<<endl;
	}
    return 0;
}