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

int k;
bool win2(int x,int y, bool inv = 0){
	if(k==1){
		if((x%2)==0 || (y%2)==0) return 1;
		return 0;
	}

	if(x<=k || y<=k){
		return inv^((x+y)%2);
	}else{
		if(x==k+1 || y==k+1) return 1;
		return win2(x-k-1,y-k-1,!inv);
	}
}

bool win3(int x,int y){
	if(k==1){
		if((x%2)==0 || (y%2)==0) return 1;
		return 0;
	}

	int cc = min(x/(k+1), y/(k+1));
	cc = max(0, cc-10);

	x-=cc*(k+1);
	y-=cc*(k+1);
	bool inv = (cc%2);
	while(x>k && y>k){
		if(x==k+1 || y==k+1)
			return 1;
		return win2(x-k-1,y-k-1,!inv);
	}
	return inv^((x+y)%2);
}

int main(){
	freopen("input.txt","r",stdin);
#ifndef LocalHost    
    freopen("output.txt","w",stdout);
#endif
	int t;
	cin>>t>>k;
	REP(i,t){
		int x,y;
		cin>>x>>y;
		if(win3(x,y)) puts("+");
		else puts("-");
	}
	return 0;
}