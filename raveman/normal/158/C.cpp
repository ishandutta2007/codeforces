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

bool OUTPUT_TO_FILE = 0;


int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	if(OUTPUT_TO_FILE)freopen("output.txt","w",stdout);
#endif

	string curr="/";
	int n;
	cin>>n;
	REP(i,n){
		string s;
		cin>>s;
		if(s=="pwd"){
			if(curr.size()==1) cout<<'/';
			else cout<<curr<<'/';
			puts("");
		}else{
			cin>>s;
			if(s[0]=='/'){
				curr="/";
				s=s.substr(1);
			}
			while(s.size()){
				if(s[0]=='.'){
					while(curr[curr.size()-1]!='/') curr.erase(curr.end()-1);
					curr.erase(curr.end()-1);
					s=s.substr(2);
					if(s.size()) s=s.substr(1);
				}else{
					if(curr[curr.size()-1]!='/') curr+="/";
					while(s.size() && s[0]!='/'){
						curr.pb(s[0]);
						s=s.substr(1);
					}
					if(s.size())
					s=s.substr(1);
				}
			}
		}
	}
#ifdef LocalHost
	if(!OUTPUT_TO_FILE) cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}