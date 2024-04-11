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

map<int,int> m;
int a[111111];
int n;

bool stupid(){
	sort(a,a+n);
	do{
		bool g = 1;
		REP(i,n)if(abs(a[i]-a[(i+1)%n])!=1){g=0;break;}
		if(g) return 1;
	}while(next_permutation(a,a+n));
	return 0;
}

bool clever(){
	m.clear();
	REP(i,n) m[a[i]]++;
	vector<pii> v;
	for(map<int,int>::iterator it = m.begin();it!=m.end();it++){
		v.pb(*it);
		//cout<<v.back().first<<' '<<v.back().second<<endl;
	}

	REP(i,v.size()){
		//cout<<"X "<<i<<" "<<v[i].first<<' '<<v[i].second<<endl;
		if(i+1<v.size()){
			if(v[i].second==0) return 0;
			if(v[i+1].first!=v[i].first+1) return 0;
			//cout<<"Y "<<v[i].second<<' '<<v[i+1].second<<endl;
			v[i+1].second-=v[i].second;
			if(v[i+1].second<0) return 0;
		}else{
			if(v[i].second) return 0;
			else return 1;
		}
	}
	//puts("FUCK");
	return 0;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	
	cin>>n;
	

	xx:
	REP(i,n){
		scanf("%d",a+i);
		//a[i]=rand()%n;
	}

	puts(clever()?"YES":"NO");

	/*bool t1 = stupid();
	bool t2 = clever();
	if(t1!=t2){
		cout<<t1<<' '<<t2<<endl;
		puts("YOOOO");
		REP(i,n) cout<<a[i]<<' ';
		puts("");	
	}
	else{
		puts("OK");
		goto xx;
	}*/
	

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}