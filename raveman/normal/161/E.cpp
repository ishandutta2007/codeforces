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

vi primes[6][6][10000];

int a[5][5];
int n,res;

void go(int pos){
	if(pos==n) res++;
	else{
		int first_part = pos;
		int val1 = 0;
		REP(i,first_part) val1 = 10 * val1 + a[i][pos];
		//cout<<n<<' '<<first_part<<' '<<a[0][pos]<<' '<<val1<<endl;
		vi &t = primes[n][first_part][val1];
		REP(i,t.size()){
			int val2 = t[i];
			for(int j=n-1;j>=pos;j--){
				a[pos][j] = val2%10;
				val2/=10;
			}
			go(pos+1);
		}
	}
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	vi pp;

	int cnt=0;
	for(int i=2;i<=99999;i++){
		bool pr = 1;
		for(int j=2;j*j<=i;j++)if(i%j==0){pr=0;break;}
		if(pr){
			pp.pb(i);
			stringstream ss;
			ss<<i;
			string s = ss.str();
			FOR(len,s.size(),6){

				FOR(first_part,1,s.size()){
					int val1=0,val2=0;
					REP(jj,first_part) val1 = 10 * val1 + s[jj] - '0';
					FOR(jj,first_part,s.size()) val2 = 10 * val2 + s[jj] - '0';
					primes[len][first_part][val1].pb(val2);
					cnt++;
				}

				s = "0" + s;
			}
		}
	}
	//cout<<pp.size()<<endl;


	//cout<<primes[2][1][9][9].size()<<endl;

	int tc;
	cin>>tc;
	REP(TC,tc){
		string s;
		cin>>s;
		n=s.size();
		REP(i,n) a[0][i]=s[i]-'0';
		res=0;
		go(1);
		cout<<res<<endl;
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}