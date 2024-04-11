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

int a1,a2,a3,a4;

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	cin>>a1>>a2>>a3>>a4;
	string s1,s2;

	//starts4
	if(a3==a4){
		if(a1>a3 && a2>=a3){
			REP(i,a1-a3-1) s1.pb('4');
			REP(i,a3) s1.pb('4'),s1.pb('7');
			REP(i,a2-a3) s1.pb('7');
			s1.pb('4');
		}
		if(a2>a3 && a1>=a3){
			REP(i,a3){
				s2.pb('7');
				s2.pb('4');
				if(i==0) REP(j,a1-a3) s2.pb('4');			
			}
			REP(i,a2-a3) s2.pb('7');			
		}
	}else if(a3==a4+1){
		if(a1>=a3 && a2>=a3){
			REP(i,a1-a3) s1.pb('4');
			REP(i,a3) s1.pb('4'),s1.pb('7');
			REP(i,a2-a3) s1.pb('7');
		}
	}else if(a4==a3+1){
		if(a2>=a4 && a1>=a4){
			REP(i,a4){
				s1.pb('7');
				if(i==a4-1) REP(j,a2-a4) s1.pb('7');
				s1.pb('4');
				if(i==0) REP(j,a1-a4) s1.pb('4');
			}
			
		}
	}

	if(s1.size()==0 && s2.size()==0) puts("-1");
	else{
		if(s1.size()==0) s1=s2;
		if(s2.size()!=0 && s2<s1) s1 = s2;
		printf("%s\n",s1.c_str());
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}