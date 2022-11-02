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
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

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

	int n,k;
	string s,t;
	cin>>n>>k>>s;
	
	t=s;
	REP(i,k){
		for(int j=i;j<n;j+=k){
			t[j]=s[i];
		}
	}
	REP(i,n)if(t[i]>s[i]){
		if(i<k){
			FOR(j,i+1,k){
				for(int z=j;z<n;z+=k){
					t[z]='0';
				}
			}
		}
		break;
	}else if(t[i]<s[i]){
		i=min(i,k-1);
		while(t[i]=='9')i--;
		i%=k;
		t[i]++;

		for(int z=i;z<n;z+=k){
			t[z]=t[i];
		}
		FOR(j,i+1,k){
			for(int z=j;z<n;z+=k){
				t[z]='0';
			}
		}
		break;
	}

	cout<<n<<endl;
	cout<<t<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}