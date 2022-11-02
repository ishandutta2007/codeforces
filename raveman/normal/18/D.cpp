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

struct bi{
	int a[701];
	bi(int val=0){
		CL(a,0);
		a[700]=val;
	}
	void add(bi s){
		int per=0;
		for(int i=700;i;i--){
			a[i]+=per;a[i]+=s.a[i];
			per=a[i]/10;
			a[i]%=10;
		}
	}
	void pom(){
		int per=0;
		for(int i=700;i;i--){
			per += a[i]*2;
			a[i]=per%10;
			per/=10;
		}
	}
	void out(){
		int pos=0;
		while(pos<700 && !a[pos]) pos++;
		FOR(i,pos,701) cout<<a[i];
	}
};

bi x[2222];

string s[5555];
int v[5555];

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
	x[0]=bi(1);
	FOR(i,1,2222) x[i]=x[i-1],x[i].pom();
	int n;
	cin>>n;
	REP(i,n) cin>>s[i]>>v[i];
	bi r;
	while(1){
		int mx = -1;
		int pos;
		REP(i,n) if(s[i]=="sell" && v[i]>mx) mx=v[i],pos=i;
		if(mx==-1) break;
		for(int i=pos;i>=0;i--){
			if(s[i]=="win" && v[i]==mx){
				FOR(j,i,pos+1) v[j]=-1;
				r.add(x[mx]);//pow(mx));
				break;
			}else if(v[i]==-1) break;
		}
		if(v[pos]>=0) v[pos]=-2;
	}
	r.out();
	return 0;
}