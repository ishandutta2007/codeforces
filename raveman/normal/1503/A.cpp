//#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<int,pii>	p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		int n;
		string s;
		cin>>n;
		getline(cin,s);
		getline(cin,s);
		string a=s,b=s;
		int n1=0;
		REP(i,n)if(s[i]=='1')n1++;
		bool g=1;
		if(n1%2==0){
			int t=0;
			REP(i,n)if(s[i]=='1'){
				if(t<n1/2){
					a[i]='(';
					b[i]='(';
				}else{
					a[i]=b[i]=')';
				}
				t++;
			}
			int s1=0,s2=0;
			REP(i,n){
				if(s[i]=='0'){
					if(s1>s2){
						a[i]=')';
						b[i]='(';
					}else{
						a[i]='(';
						b[i]=')';
					}
				}
				if(a[i]=='(')s1++;
				else s1--;
				if(b[i]=='(')s2++;
				else s2--;
				if(s1<0 || s2<0)g=0;
			}
			//cout<<s1<<' '<<s2<<' '<<a<<' '<<b<<endl;
			if(s1||s2)g=0;
		}else g=0;
		if(!g)puts("NO");
		else cout<<"YES\n"<<a<<"\n"<<b<<"\n";
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}