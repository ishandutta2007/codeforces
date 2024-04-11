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

map< pair<pii,pii> , int> r[33];

int solve(int l1,int r1,int l2,int r2,int step){
	if(step==1){
		return 1;
	}

	if(r[step].count(make_pair(pii(l1,r1),pii(l2,r2))))
		return r[step][make_pair(pii(l1,r1),pii(l2,r2))];

	int middle_pos = ((1<<step)-1)/2;

	int res = 0;
	
	if(l1<=middle_pos && middle_pos<=r1)
		if(l2<=middle_pos && middle_pos<=r2){
			res = min(r1,r2)-max(l1,l2) + 1;
		}

	REP(type1,2)REP(type2,2){
		int from1 = l1;
		int to1 = min(middle_pos - 1, r1);
		if(type1){
			from1 = max(l1, middle_pos + 1);
			to1 = r1;

			from1 -= (middle_pos + 1);
			to1 -= (middle_pos + 1);
		}

		int from2 = l2;
		int to2 = min(middle_pos - 1, r2);
		if(type2){
			from2 = max(l2, middle_pos + 1);
			to2 = r2;

			from2 -= (middle_pos + 1);
			to2 -= (middle_pos + 1);
		}

		if(from1>=0 && from2>=0 && from1<=to1 && from2<=to2){
			if(res < min(to2-from2+1,to1-from1+1))
				res = max(res, solve(from1,to1,from2,to2,step-1));
		}
	}

	return r[step][make_pair(pii(l1,r1),pii(l2,r2))]=res;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int l1,r1,l2,r2;
	cin>>l1>>r1>>l2>>r2;
	l1--,r1--,l2--,r2--;
	cout<<solve(l1,r1,l2,r2,30)<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}