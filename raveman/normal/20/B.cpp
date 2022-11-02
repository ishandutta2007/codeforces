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

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	ll a,b,c;
	cin>>a>>b>>c;
	if(a==0){
		if(b==0){
			if(c==0) puts("-1");
			else puts("0");
		}else{
			puts("1");
			printf("%.5lf\n",double(-c)/b);
		}
	}else{
		ll d = b*b-4*a*c;
		if(d<0) puts("0");
		else if(d==0){
			puts("1");
			printf("%.5lf\n",double(-b)/2/a);
		}else{
			puts("2");
			double D = sqrt(double(d));
			if(a<0) D=-D;
			printf("%.5lf\n",double(-b-D)/2/a);
			printf("%.5lf\n",double(-b+D)/2/a);
		}
	}
	return 0;
}