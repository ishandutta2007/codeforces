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

int p[1111];
int P(int v){return p[v]==v? v:p[v]=P(p[v]);}
void join(int p1,int p2){
	p1 = P(p1);
	p2 = P(p2);
	if(p1!=p2) p[p2]=p1;
}
map<char,int> w;
int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>s;
	n=s.size();
	REP(i,n) p[i]=i;
	for(int i=2;i<=n;i++){
		bool pr = 1;
		for(int j=2;j*j<=i;j++)if(i%j==0){pr=0;break;}
		for(int z=1;z<=n/i;z++) join(i-1,z*i-1);
		
	}

	vector<pii> v;
	int bb = 0;
	REP(i,n)if(P(i)==i){
		int c = 0;
		REP(j,n)if(P(j)==i) c++;
		v.pb(pii(c,i));
		if(c>bb) bb=c;
		//cout<<c<<endl;
	}
	SORT(v);
	reverse(v.begin(),v.end());
	REP(i,n) w[s[i]]++;
	char mx;
	int num=0;
	for(map<char,int>::iterator it = w.begin();it!=w.end();it++){
		if(it->second>num) num=it->second,mx=it->first;
		//cout<<it->first<<' '<<it->second<<endl;
	}
	//cout<<bb<<' '<<num<<endl;
	if(bb>num) puts("NO");
	else{
		puts("YES");
		string t;
		REP(i,n) t.pb(' ');
		REP(i,n)if(P(i)==P(1)) {t[i]=mx;w[mx]--;}
		REP(i,n)if(t[i]==' '){
			while(w.begin()->second==0) w.erase(w.begin());
			t[i] = w.begin()->first;
			w.begin()->second--;
		}
		cout<<t<<endl;
	}
	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}