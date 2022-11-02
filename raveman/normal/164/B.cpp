#pragma comment(linker, "/STACK:65777216")
 
#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

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

int n,m;
int a[2111111];
int b[2111111];
int p1[1111111];
int p2[1111111];

int solve_st(vi v1, vi v2){
	int res = 0;
	int p2 = 0;
	int p1 = 0;
	while(p1<v1.size()){
		while(p2<v2.size() && v2[p2]!=v1[p1]) p2++;
		if(p2<v2.size()){
			p1++;
		}else break;
	}
	return p1;
}
int stupid(){
	int best = 0;
	REP(i,n)REP(k,m){
		vi v1;
		REP(j,n) v1.pb(a[i+j]);
		vi v2;
		REP(j,m) v2.pb(b[k+j]);
		best = max(best, solve_st(v1,v2));
	}
	return best;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	//start:
	cin>>n>>m;
	REP(i,n) scanf("%d",a+i),a[i+n]=a[i];
	REP(i,m) scanf("%d",b+i),b[i+m]=b[i];
	/*
	n=1+rand()%5;
	m=1+rand()%5;
	CL(a,-1);
	CL(b,-1);
	int n1 = n;
	int n2 = m;
	int it = 1;
	while(n1||n2){
		int p1 = rand()%(n+1);
		int p2 = rand()%(m+1);
		if(p1<n && a[p1]==-1) a[p1] = it,n1--;
		if(p2<m && b[p2]==-1) b[p2] = it,n2--;
		it++;
	}
	REP(i,n) a[i+n]=a[i];
	REP(i,m) b[i+m]=b[i];
	*/
	CL(p1,-1);CL(p2,-1);
	REP(i,n) p1[a[i]]=i;
	REP(i,m) p2[b[i]]=i;

	int best = 0;
	int enda = -1;
	deque<ll> d;
	REP(starta,n){
		if(enda<starta){
			if(p2[a[starta]]==-1) continue;
			d.pb(p2[a[starta]]);
			enda=starta;
		}

		while(enda+1<starta+n && p2[a[enda+1]]!=-1){
			ll nextpos = p2[a[enda+1]];
			ll diff = d.back() - nextpos;
			if(diff>0) nextpos += diff/m*m;
			while(nextpos < d.back()) nextpos += m;
			//cout<<enda+1<<' '<<a[enda+1]<<' '<<nextpos<<endl;
			ll frst = d.front();
			if(nextpos > frst + m ) break;
			d.pb(nextpos);
			enda++;
		}


		//cout<<"F "<<starta<<' '<<enda<<endl;
		best = max(best, enda-starta+1);

		d.pop_front();
	}
	/*if(best!=stupid() || best>=4){
		cout<<n<<' '<<m<<endl;
		REP(i,n) cout<<a[i]<<' ';puts("");
		REP(i,m) cout<<b[i]<<' ';puts("");
		cout<<best<<' '<<stupid()<<endl;
		return 0;
	}else cout<<best<<" OK"<<endl;
	goto start;*/
	cout<<best<<endl;
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}