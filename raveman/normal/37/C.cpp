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

int n;
int a[1111];
vector<string> r;

int main(){
#ifdef LocalHost    
	freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n) cin>>a[i];

	r.resize(n);
	string prev = "";
	REP(tc,n){
		int best = -1;
		REP(i,n) if(a[i]>0 && (best==-1 || a[i]< a[best])) best = i;

		int len = a[best]; a[best] = 0;
		if(prev != ""){
			int pos = prev.size() -1;
			while(pos>=0 && prev[pos] == '1') prev[pos] = '0', pos--;
			if(pos<0){
				puts("NO");
				return 0;
			}
			prev[pos] = '1';
		}
		while(prev.size() !=len) prev.pb('0');
		r[best] = prev;
	}

	puts("YES");
	REP(i,n) printf("%s\n",r[i].c_str());

	return 0;
}