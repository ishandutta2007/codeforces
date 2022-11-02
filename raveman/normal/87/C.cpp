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

int g[111111];
int w[111111];
set<int> s;

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	int best = -1;
	cin>>n;
	g[1] = 0;
	g[2] = 0;
	for(int i=3;i<=n;i++){
		s.clear();
		for(int k=2;;k++){
			int x = (2*i / k - k + 1) / 2;
			if(x<1) break;
			if((2*x+k-1)*k==2*i){
				int val = w[x-1]^w[x+k-1];
				if(val==0 && i==n && best==-1)
					best = k;
				s.insert(val);
			}
		}
		int res = 0;
		while(s.count(res)) res++;
		g[i] = res;

		w[i] = w[i-1]^g[i];
	}

	cout<<best<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}