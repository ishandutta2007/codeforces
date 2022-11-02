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

string s;
int n;
int best = 0;

int a[111][55][211][3];
void go(int pos,int change,int x,int dx){
	if(a[pos][change][x+100][dx+1]) return;
	a[pos][change][x+100][dx+1]=1;
	if(pos==s.size()){
		if(change==0) best = max(best, abs(x));
		return;
	}
	REP(i,change+1){
		int val = (s[pos]=='F');
		if(i%2) val^=1;

		go(pos+1,change-i,x+(val==1?dx:0),dx*(val==0?-1:1));
	}
}

int main(){
#ifdef LocalHost

    freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
#endif
	
	cin>>s>>n;
	go(0,n,0,1);
	cout<<best<<endl;
 
#ifdef LocalHost
    cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}