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

int n,m,p;
int l[1111111];

int d[5055][5055];
int go(int len,int num){
	if(len==0) return num==0;
	if(num<=0) return 0;
	if(d[len][num]!=-1) return d[len][num];
	ll res = 0;
	res = ll(go(len-1,num-1))*num;
	res += ll(go(len-1,num))*(num-1);
	res %= p;
	return d[len][num] = res;
}

vi pr;
vi nx;

int C[5555];

int gcd(int a,int b){
	while(a&&b)
		if(a>b) a%=b;
		else b%=a;
	return a+b;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
#endif

	
	cin>>n>>m>>p;
	//n=10000000/5000;

	C[0] = 1;
	vi v;
	FOR(i,1,min(m,5000)+1){
		v.pb(m-i+1);
		int jj = i;
		ll d = 1;
		REP(j,v.size()){
			if(jj!=1){
				int g = gcd(v[j], jj);
				jj/=g;
				v[j]/=g;
			}
			d *= v[j];
			d %= p;
		}
		C[i] = d;
		//cout<<"C "<<i<<" = "<<d<<endl;
	}

	REP(i,n) scanf("%d",l+i);
	CL(d,-1);

	pr.clear();
	pr.pb(1);

	REP(i,n){
		
		int sum = 0;
		REP(j,pr.size()){
			sum += pr[j];
			if(sum>=p) sum-=p;
		}

		nx.clear();
		nx.resize(l[i]+1);

		FOR(j,1,l[i]+1)if(j<=m){
			int sum1 = sum;
			int sum2 = 0;
			if(pr.size()>j){
				sum2=pr[j];
				sum1-=sum2;
				if(sum1<0) sum1+=p;
			}

			int cc = C[j];

			ll t = cc * ll(sum1);//go(l[i],j);
			//cout<<t<<endl;
			
			cc--;
			if(cc<0) cc+=p;

			t += cc * ll(sum2);
			

			nx[j] = ((t%p)*go(l[i],j))%p;
			//if(nx[j]>=p) nx[j]-=p;
		}

		pr = nx;

		//REP(j,pr.size())
			//cout<<"after level "<<i<<", num colors "<<j<<" = "<<pr[j]<<endl;
	}

	int res = 0;
	REP(i,pr.size()){
		res += pr[i];
		if(res>=p) res-=p;
	}
	cout<<res<<endl;
	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}