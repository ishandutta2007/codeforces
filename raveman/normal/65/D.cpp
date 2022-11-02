#pragma comment(linker, "/STACK:60777216")  

#include <algorithm>
#include <iostream>
#include <complex>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <ctime>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define sz(a)			int(a.size())
#define all(a)			(a).begin(), (a).end()
#define CL(a, b)		memset(a, b, sizeof a) 
#define FOR(i, a, b)	for (int i(a); i < (b); ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(a)			sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define pb				push_back
#define SORT(a)			sort(all(a))

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

string f[]={"Gryffindor","Hufflepuff","Ravenclaw","Slytherin"};

int n;
string s;

typedef pair<pii,pii> p4;

set<p4> x;
int m;
void go(int a,int b,int c,int d){
	pii x1(a,b),x2(c,d);
	p4 xx(x1,x2);
	if(x.count(xx)) return;
	x.insert(xx);

	int q = a + b + c + d;
	if(q>=n){
		int mn = min(min(a,b),min(c,d));
		if(a==mn) m|=1;
		if(b==mn) m|=2;
		if(c==mn) m|=4;
		if(d==mn) m|=8;
		return;
	}

	char cc = s[q];
	if(cc=='G') a++;
	else if(cc=='H') b++;
	else if(cc=='R') c++;
	else if(cc=='S') d++;
	
	if(cc=='?'){
		int mn = min(min(a,b),min(c,d));
		if(a==mn) go(a+1,b,c,d);
		if(b==mn) go(a,b+1,c,d);
		if(c==mn) go(a,b,c+1,d);
		if(d==mn) go(a,b,c,d+1);
	}else go(a,b,c,d);
}

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
#endif

	cin>>n;
	cin>>s;
	//REP(i,n) s.pb('?');
	go(0,0,0,0);

	//cout<<x.size()<<endl;
	REP(i,4) if(m&(1<<i)){
		cout<<f[i]<<endl;
	}
	//cout<<clock()<<endl;
	return 0;
}