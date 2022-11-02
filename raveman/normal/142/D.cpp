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

int a[11];
bool go(vi v,int k){
	REP(i,v.size()){
		//cout<<v[i]<<endl;
		REP(j,10) if(v[i]&(1<<j)) a[j]++;
	}
	REP(i,11) if(a[i]%(k+1)) return 1;
	return 0;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	int n,m,k;
	cin>>n>>m>>k;
	bool cangm=0,canrm=0;
	vi v;
	REP(i,n){
		string s;
		cin>>s;
		int posg=-1;
		int posr=-1;
		int pose=-1;
		REP(j,m) if(s[j]=='-') pose=j;
		else if(s[j]=='G') posg=j;
		else posr=j;
		if(posg!=-1 && posr!=-1) v.pb(abs(posg-posr)-1);
		else{
			if(posg!=-1 && pose!=-1) cangm=1;
			if(posr!=-1 && pose!=-1) canrm=1;
		}
	}
	if(cangm && canrm) puts("Draw");
	else{
		bool first = go(v,k);
		if(first && !canrm || v.size()==0 && cangm && !canrm) puts("First");
		else if(!first && !cangm || v.size()==0 && !cangm) puts("Second");
		else puts("Draw");
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}