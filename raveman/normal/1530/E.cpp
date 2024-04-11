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

int p[111111];

void solve(){
	int tc;
	cin>>tc;
	string s;
	getline(cin,s);
	REP(TC,tc){
		getline(cin,s);
		SORT(s);
		if(s[0]==s.back())cout<<s<<"\n";
		else{
			bool f=0;
			REP(i,s.size())if(i==0 || s[i-1]!=s[i])if(i+1==s.size() || s[i+1]!=s[i]){
				f=1;
				cout<<s[i]<<s.substr(0,i)<<s.substr(i+1)<<"\n";
				break;
			}
			if(!f){
				int nmf = 0;
				REP(i,s.size())if(s[i]==s[0])nmf++;
				int other = s.size() - nmf;
				if(other >= nmf-2){
					cout<<s[0]<<s[0];
					REP(i,nmf-2)cout<<s[nmf+i]<<s[0];
					cout<<s.substr(nmf+nmf-2);
					puts("");
				}else{
					if(s.back()==s[nmf]){
						cout<<s[0]<<s.substr(nmf)<<s.substr(1,nmf-1)<<"\n";
						//cout<<s<<endl;
					}else{
						cout<<s[0]<<s[nmf]<<s.substr(1,nmf-1);
						FOR(i,nmf+1,s.size())if(s[i]!=s[i-1]){
							cout<<s[i]<<s.substr(nmf+1,i-(nmf+1))<<s.substr(i+1);
							break;
						}
						puts("");
						//cout<<s<<endl;
					}
				}
			}
		}
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	solve();
	return 0;
	string s;
	cin>>s;
	SORT(s);
	do{
		REP(i,s.size())p[i]=0;
		p[0]=-1;
		int curr=-1;
		FOR(i,1,s.size()){
			while(curr>=0 && s[curr+1]!=s[i])curr=p[curr];
			if(s[curr+1]==s[i])curr++;
			p[i]=curr;
		}
		int mv=0;
		cout<<s;
		REP(i,s.size())cout<<" "<<p[i],mv=max(mv,p[i]);//puts("");
		if(mv==0){ puts ("YEESSSS!!!");
		break;}
		else puts("");
	}while(next_permutation(s.begin(),s.end()));

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}