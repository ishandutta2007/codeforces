#pragma comment(linker, "/STACK:65777216")
 
#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

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

bool OUTPUT_TO_FILE = 0;


int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	if(OUTPUT_TO_FILE)freopen("output.txt","w",stdout);
#endif

	int s1=0,s2=0,s3=0,s4=0;
	int n;
	cin>>n;
	REP(i,n){
		int x;
		scanf("%d",&x);
		if(x==1) s1++;
		if(x==2) s2++;
		if(x==3) s3++;
		if(x==4) s4++;
	}

	int res = s4;
	res += s3;

	s1 -= s3;
	s1 = max(s1, 0);

	res += s2/2;
	s2%=2;

	if(s2){
		res++;
		s1 -= 2;
		s1 = max(s1,0);
	}

	res += (s1+3)/4;

	cout<<res<<endl;

#ifdef LocalHost
	if(!OUTPUT_TO_FILE) cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}