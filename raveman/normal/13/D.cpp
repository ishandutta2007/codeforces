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

int n,m;
int x[555],X[555],y[555],Y[555];

vector<pair<double,int> > v;

ll sq(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
	return (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n) cin>>x[i]>>y[i];
	REP(i,m) cin>>X[i]>>Y[i];

	int res = 0;

	REP(i,n){
		v.clear();
		REP(j,n) if(i!=j && (y[j] > y[i] || y[j] == y[i] && x[j] >= x[i])) 
			v.pb(pair<double,int> ( atan2(y[j]-y[i]+0., x[j]-x[i]) , j + 1));
		REP(j,m) if((Y[j] > y[i] || Y[j] == y[i] && X[j] >= x[i]))
			v.pb(pair<double,int> ( atan2(Y[j]-y[i]+0., X[j]-x[i]) , - j - 1));
		SORT(v);

		REP(j,v.size()) if(v[j].second > 0){
			int beg = v[j].second - 1;
			int pos = -1;
			FOR(k,j+1,v.size()){
				if(v[k].second > 0){
					int curr  = v[k].second - 1;
					if(pos == -1 || sq(x[beg], y[beg], X[pos], Y[pos], x[curr], y[curr]) > 0)
						res ++;
				}else{
					int curr  = -v[k].second - 1;
					if(pos == -1 || sq(x[beg], y[beg], X[pos], Y[pos], X[curr], Y[curr]) > 0)
						pos = curr;
				}
			}

		}
	}

	cout<<res<<endl;
	
	return 0;
}