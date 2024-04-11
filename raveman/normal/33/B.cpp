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

string s1,s2;
int a[33][33];

const int inf = 1011111111;

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
	getline(cin,s1);
	getline(cin,s2);
	if(s1.size()!=s2.size()){
		puts("-1");
		return 0;
	}
	int m;
	cin>>m;
	REP(i,26)REP(j,26) a[i][j]=(i==j?0:inf);
	REP(i,m){
		char c1,c2;
		int x;
		scanf(" %c %c %d",&c1,&c2,&x);
		a[c1-'a'][c2-'a']=min(x,a[c1-'a'][c2-'a']);
	}
	REP(k,26)REP(i,26)REP(j,26)
		a[i][j]=min(a[i][j],a[i][k]+a[k][j]);

	int res = 0;
	REP(i,s1.size()){
		int x = inf;
		REP(j,26) x=min(x,a[s1[i]-'a'][j]+a[s2[i]-'a'][j]);
		if(x==inf){
			puts("-1");
			return 0;
		}else res+=x;
		REP(j,26) if(x==a[s1[i]-'a'][j]+a[s2[i]-'a'][j]){
			s1[i]=char('a'+j);
			break;
		}
		
	}
	cout<<res<<endl;
	printf("%s\n",s1.c_str());
	return 0;
}