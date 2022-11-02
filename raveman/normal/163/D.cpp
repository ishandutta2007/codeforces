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

int k;
ll  p[111];
int d[111];
int r[111];
ll st[111][111];
ll best,besta,bestb,bestc;
ll v;
ll rs,rsb,rsa;
ll VV;
void go(int pos,ll a,ll b){
	if(rs!=-1 && rs <= a+b || a>VV) return;
	if(pos==k){
		ll t = a+b;
		if(rs==-1 || rs>t){
			rs = t;
			rsa=a;
			rsb=b;
		}
	}else{
		int i1 = r[pos]/2;
		int i2 = i1 + 1;
		for(;;){
			if(i1<0 && i2>r[pos]) break;
			if(i1>=0)go(pos+1,a*st[pos][i1],b*st[pos][r[pos]-i1]);
			if(i2<=r[pos])go(pos+1,a*st[pos][i2],b*st[pos][r[pos]-i2]);
			i1--,i2++;
		}
		//REP(i,r[pos]+1) go(pos+1,a*st[pos][i],b*st[pos][r[pos]-i]);
	}
}

ll getEst(ll v){
	return 2*sqrt(v+0.);
}

ll vv;
void go2(int pos,ll a){
	if(best!=-1 && best<=a*2 || a > vv) return;
	if(pos==k){
		
		ll ab = v / a;
		ll s = getEst(ab);
		ll est = a * s  + ab;
		if(best==-1 || best>est){
			rs = -1;
			VV = sqrt(ab+0.1)+10;
			go(0,1,1);
			ll val = a * rs + ab;
			if(best==-1 || best>val){
				best = val;
				besta=a;
				bestb=rsa;
				bestc=rsb;
			}
		}
	}else{
		int i1 = d[pos]/3;
		int i2 = i1 + 1;
		for(;;){
			if(i1<0 && i2>d[pos]) break;
			if(i1>=0){
				r[pos] = d[pos] - i1;
				go2(pos+1,a*st[pos][i1]);
			}
			if(i2<=d[pos]){
				r[pos] = d[pos] - i2;
				go2(pos+1,a*st[pos][i2]);
			}
			i1--;
			i2++;
		}
		/*REP(i,d[pos]+1){
			r[pos] = d[pos]-i;
			go2(pos+1,a*st[pos][i]);
		}*/
	}
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>k;
		v = 1;
		REP(i,k){
			cin>>p[i];
			cin>>d[i];
			st[i][0]=1;
			FOR(j,1,d[i]+1) st[i][j] = st[i][j-1]*p[i];			
			v*=st[i][d[i]];
		}
	//	int it = 0;
//start:
		//it++;
		//if(it==500) break;
		best = -1;
		vv = pow(v,1./3)+10;
		go2(0,1);
		//goto start;
		cout<<2*best<<' '<<besta<<' '<<bestb<<' '<<bestc<<endl;
	}
	

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}