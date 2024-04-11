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

int n;
int x[111],X[111];
int y[111],Y[111];

const double eps = 1e-9;

int main(){
#ifdef LocalHost    
	freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
	cin>>n;
	REP(i,n) cin>>x[i]>>y[i]>>X[i]>>Y[i],x[i]*=2,y[i]*=2,X[i]*=2,Y[i]*=2;
	int m = 1;
	for(int i=1;i<n;i++){
		bool g = 1;
		ll xx = 0,yy=0;
		ll mm=0;
		for(int j=i;j;j--){
			ll xx2 = (x[j]+X[j])/2;
			ll yy2 = (y[j]+Y[j])/2;
			
			
			ll mm2 = (X[j]-x[j])*(X[j]-x[j])*(X[j]-x[j]);
			if(mm2<0) mm2=-mm2;
			xx += xx2*mm2;
			yy += yy2*mm2;
			
			mm+=mm2;

			if(xx > mm*max(x[j-1],X[j-1]) ) {g=0;break;}
			if(xx < mm*min(x[j-1],X[j-1]) ) {g=0;break;}
			if(yy > mm*max(y[j-1],Y[j-1]) ) {g=0;break;}
			if(yy < mm*min(y[j-1],Y[j-1])) {g=0;break;}
		}
		if(!g) break;
		m++;
	}
	cout<<m<<endl;
	return 0;
}