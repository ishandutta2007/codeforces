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

int n,k,m;
ll a[55],b[55];
int c[55],d[55];
ll  r[55][55][111];
int f1[55][55][111];
int f2[55][55][111];
int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>k;
	REP(i,m){
		cin>>a[i]>>b[i]>>c[i];
		d[i]=i+1;
	}
	REP(i,m)REP(j,i) if(c[i]<c[j]){
		swap(c[i],c[j]);
		swap(a[i],a[j]);
		swap(b[i],b[j]);
		swap(d[i],d[j]);
	}
	CL(r,0);CL(f1,-1),CL(f2,-1);
	REP(i,m)REP(diff,b[i]-a[i]+1)
		r[0][i][diff] = a[i] +diff;
	ll val = 0;
	REP(day,n-1) REP(i,m) REP(diff,b[i]-a[i]+1)if(val=r[day][i][diff]){
		FOR(next,i+1,m)if(c[next]>c[i]){
			ll currcost = a[i] + diff;
			ll c1 = currcost + k;
			ll c2 = currcost * k;
			if(c1>=a[next] && c1<=b[next]){
				int ndiff = c1 - a[next];
				if(r[day+1][next][ndiff] < val + a[next] + ndiff)
					r[day+1][next][ndiff] = val + a[next] + ndiff,
					f1[day+1][next][ndiff] = i,
					f2[day+1][next][ndiff] = diff;
			}
			if(c2>=a[next] && c2<=b[next]){
				int ndiff = c2 - a[next];
				if(r[day+1][next][ndiff] < val + a[next] + ndiff)
					r[day+1][next][ndiff] = val + a[next] + ndiff,
					f1[day+1][next][ndiff] = i,
					f2[day+1][next][ndiff] = diff;
			}
		}
	}

	ll best = -1;
	int x = 0;
	ll D = 0;
	REP(i,m)REP(diff,b[i]-a[i]+1) if(r[n-1][i][diff]!=-1 && r[n-1][i][diff]>=best){
		best = r[n-1][i][diff];
		x = i;
		D = diff;
	}
	if(best<=0) puts("NO");
	else{
		puts("YES");
		int curr = x;
		int day = n-1;
		vector<int> subj;
		vector<ll>  home;
		while(1){
			subj.pb(d[curr]);
			home.pb(a[curr]+D);

			if(day==0) break;

			int tcurr = curr;
			curr = f1[day][tcurr][D];
			D    = f2[day][tcurr][D];
			day--;
		}
		REP(i,n)
			cout<<subj[n-1-i]<<' '<<home[n-1-i]<<endl;
		
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}