#pragma comment(linker, "/STACK:60777216")  

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
typedef vector<ll> vl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

ll n,a,b,c;
string s;

ll solve(int t){
	if(n==1)return 0;
	ll res=0;
	int bz=n,ez=0;
	REP(i,n)if(s[i]=='1'){
		bz=i;
		break;
	}
	if(bz==n){
		return a;
	}
	for(int i=n-1;i>=0;i--)if(s[i]=='1'){
		ez=(n-1)-i;
		break;
	}

	int n1g=0;
	vi zg;
	for(int i=0;i<n;i++)if(s[i]=='1'){
		int j = i + 1;
		while(j<n && s[j]=='1'){
			n1g++;
			j++;
		}
		if(j<n){
			int nz=0;
			while(j<n && s[j]=='0'){
				nz++;
				j++;
			}
			if(j<n){
				zg.pb(nz);
			}
		}
		i=j-1;
	}
	SORT(zg);
	reverse(zg.begin(),zg.end());
	int pos = int(zg.size())-1;
	// bz - beginning zeros
	// ez - end zeros
	// zg - zero groups
	// n1g - number of 1 groups

	//cout<<"!"<<bz<<' '<<ez<<' '<<n1g<<' '<<t<<endl;

	t=1-t;
	while(1){
		t=1-t;
		//cout<<"it "<<t<<endl;
		if(t==0){
			// op 0 or 2
			if(n1g==0){
				if(b>c){
					if(!zg.empty() && zg.back() == 1){
						zg.pop_back();
						res-=c;
						n1g++;
						continue;
					}
				}
				//DO A
				while(pos>=0 && zg[pos]==1)pos--;
				if(pos>=0){
					res+=a;
					zg[pos]--;
					continue;
				}
				if(bz>1){
					bz-=1;
					res+=a;
					continue;
				}
				if(ez>1){
					ez-=1;
					res+=a;
					continue;
				}
			}else{
				// DO A
				while(pos>=0 && zg[pos]==1)pos--;
				if(pos>=0){
					res+=a;
					zg[pos]--;
					continue;
				}
				if(bz>1){
					bz-=1;
					res+=a;
					continue;
				}
				if(ez>1){
					ez-=1;
					res+=a;
					continue;
				}

				// DO C
				if(b>c){
					if(!zg.empty() && zg.back()==1){
						zg.pop_back();
						res-=c;
						n1g++;
						continue;
					}
					if(bz){
						bz--;
						res-=c;
						continue;
					}
					if(ez){
						ez--;
						res-=c;
						continue;
					}
				}
			}
			break;
		}else{
			// op 1
			if(n1g>0){n1g--,res+=b;continue;}
			break;
		}
	}
	//cout<<" = "<<res<<endl;
	return res;
}


map<string,ll> st[2];

ll stupid(string s,int type){
	if(s.size()<=1)return 0;
	if(st[type].count(s))return st[type][s];
	ll best=0;
	if(type==0){
		//0
		FOR(i,1,s.size())if(s[i]=='0' && s[i-1]=='0'){
			string t = s;
			t.erase(t.begin()+i);
			best = max(best,a+stupid(t,1-type));
		}
		//2
		REP(i,s.size())if(s[i]=='0'){
			string t = s;
			t.erase(t.begin()+i);
			best=max(best,-c+stupid(t,1-type));
		}
	}
	if(type==1){
		//1
		FOR(i,1,s.size())if(s[i]=='1' && s[i-1]=='1'){
			string t = s;
			t.erase(t.begin()+i);
			best = max(best,b+stupid(t,1-type));
		}
	}
	return st[type][s]=best;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n>>a>>b>>c>>s;
		ll r1 = max(solve(0),solve(1));
		cout<<r1<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}