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

int a[1111];

int main(){
#ifdef LocalHost    
	freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	REP(i,n) cin>>a[i];
	sort(a,a+n);
	int mx = 0;
	int mn = 0;
	REP(i,n){
		int j = i;
		while(j<n && a[j]==a[i]) j++;
		mx = max(mx, j-i);
		if(i==0 || a[i]!=a[i-1]) mn++;
	}
	cout<<mx<<' '<<mn<<endl;
	return 0;
}