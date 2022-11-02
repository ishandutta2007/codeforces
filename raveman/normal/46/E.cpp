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

int n,m;
int a[1555][1555];
ll d[1555][1555];
ll ml[1555],mr[1555];

const ll inf = 1000000000000000000ll;

int main(){
#ifdef LocalHost    
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n)REP(j,m) scanf("%d",&a[i][j]);
	REP(i,n){
		int sum = 0;
		REP(j,m){
			sum += a[i][j];

			d[i][j] = sum;

			if(i&1) d[i][j] += (j+1>=m ? -inf : mr[j+1]);
			else d[i][j] += (j==0 ? -inf : ml[j-1]);
		}
		REP(j,m){
			ml[j] = max((j?ml[j-1]:-inf),d[i][j]);
		}
		for(int j = m-1;j>=0;j--){
			mr[j] = max((j+1>=m?-inf:mr[j+1]),d[i][j]);
		}
	}
	ll res = -inf;
	REP(i,m) res = max(res,d[n-1][i]);
	cout<<res<<endl;

	return 0;
}