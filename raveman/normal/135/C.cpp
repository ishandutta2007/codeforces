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

char s[111111];
char b[111111];
int n;

string solve(){
	//cout<<"solve "<<b<<endl;

	int r1 = (n-2)/2;
	int r2 = (n-2+1)/2;
	string res;
	REP(i,n){
		if(b[i]=='1' && r2) {r2--;continue;}
		if(b[i]=='0' && r1) {r1--;continue;}
		res.pb(b[i]);
	}
	return res;
}

int main(){
#ifdef LocalHost

    freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
#endif

	gets(s);
	n = strlen(s);

	vector<string> res;

	int numzero = 0, numone=0;
	REP(i,n) if(s[i]=='0') numzero++;
	else if(s[i]=='1') numone++;

	if((n-2)/2>=numzero) res.pb("11");
	if((n-2+1)/2>=numone) res.pb("00");

	int q = n - numzero - numone;

	REP(qones, q+1){
		int tones = numone + qones;
		int tzeros = numzero + q - qones;

		tzeros -= (n-2)/2;
		tones -= (n-2+1)/2;

		if(tzeros >=0 && tones>=0 && tzeros == tones  && tzeros == 1){
			int numq=0;
			REP(i,n) if(s[i]=='0' || s[i]=='1') b[i]=s[i];
			else{
				numq++;
				if(numq<=qones) b[i]='1';
				else b[i]='0';
			}
			res.pb(solve());

			numq=0;
			for(int i=n-1;i>=0;i--) if(s[i]=='0' || s[i]=='1') b[i]=s[i];
			else{
				numq++;
				if(numq<=qones) b[i]='1';
				else b[i]='0';
			}
			res.pb(solve());

		}
	}

	UN(res);
	REP(i,res.size()) cout<<res[i]<<endl;

	

	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}