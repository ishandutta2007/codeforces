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

int a[333333];
int n;

ll solve(){
	ll res=0;
	int num=0;
	int start=0;
	REP(i,n){
		//cout<<i<<' '<<res<<' '<<num<<' '<<start<<endl;
		int t = a[i];
		if(num==0){
			res+=t/2;
			t%=2;
			if(t==1 && i+1<n)num=1,res++,start=0;
		}else{
			int diff = t - (start+(num-1)*2) - 1;
			res += diff/2;
			t -= diff/2*2;


			if(start==0){
				if(diff%2==0) num=num-1;
				else num=num;
			}else if(start==1){
				if(diff%2==0)num=num;
				else num=num+1;
				
			}
			start^=1;

			if(i+1>=n) num=0;
			else while(a[i+1]<1+start+(num-1)*2)num--;

			res+=num;

		}
	}
	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	ll sum=0;
	REP(i,n)scanf("%d",a+i),sum+=a[i];
	cout<<solve()<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}