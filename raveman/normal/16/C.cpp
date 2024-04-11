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

int gcd(int a,int b){
	while(a&&b)
		if(a>b) a%=b;
		else b%=a;
		return a+b;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
	int a,b,x,y;
	cin>>a>>b>>x>>y;
	int g = gcd(x,y);
	x/=g,y/=g;
	int d = min(a/x, b/y);
	cout<<d*x<<' '<<d*y<<endl;
	
	return 0;
}