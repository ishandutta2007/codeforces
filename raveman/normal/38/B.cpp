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

int main(){
#ifdef LocalHost    
	freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	string s1,s2;
	cin>>s1>>s2;
	int x1 = s1[0]-'a';int x2 = s2[0]-'a';
	int y1 = s1[1]-'1';int y2 = s2[1]-'1';
	int res =0 ;
	REP(i,8)REP(j,8)if(i!=x1 || j!=x2)
		if(i!=x2 || j!=y2){
			if(i==x1 || j==y1) continue;
			if(abs(x1-i) + abs(y1-j)==3) continue;

			if(abs(x2-i)+abs(y2-j)==3 && abs(x2-i) && abs(y2-j)) continue;
			res++;
		}
	cout<<res<<endl;
	return 0;
}