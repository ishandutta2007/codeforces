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

typedef pair<double,int> pdi;

const double eps = 1e-8;
const double pi = acos(-1.);

int n;
int x[1111],y[1111],r[1111];

double getA(double a){
	if(a<0) return a+2*pi;
	return a;
}
void add(vector<pdi> &v, double a1,double a2,int q){
	if(a2<=2*pi){
		v.pb(pdi(a1+eps,q+1));
		v.pb(pdi(a2-eps,-q-1));
	}else{
		v.pb(pdi(0,q+1));
		v.pb(pdi(a2-2*pi-eps,-q-1));
		v.pb(pdi(a1+eps,q+1));
		v.pb(pdi(2*pi,-q-1));
	}
}

double go(int i,int j,double a,double b,double c){
	if(a<0 || a<eps && b<0) a=-a,b=-b,c=-c;
	//cout<<a<<' '<<b<<' '<<c<<endl;
	double xx = a*r[i];
	double yy = b*r[i];
	if(fabs(fabs(xx*a+yy*b+c)-0)>eps) xx = -xx, yy = -yy;
	//cout<<xx<<' '<<yy<<endl;
	return getA(atan2(yy,xx));
}

bool good(int i,int j,double a){
	double xx = cos(a)*r[i];
	double yy = sin(a)*r[i];
	double A = cos(a), B = sin(a);
	double C = -(xx*A+yy*B);
	//cout<<A*xx+B*yy+C<<endl;
	return fabs(A*x[j]+B*y[j]+C)<r[j];
	//return 1;
}

int solve(){
	int res = 1;
	REP(i,n){
		REP(j,n)if(i!=j)x[j]-=x[i],y[j]-=y[i];
		vector<pdi> v;
		REP(j,n)if(i!=j){
			double ang[9];int pos=0;
			REP(t1,1)REP(t2,2){
				double c = (t1?-r[i]:r[i]);
				double E = (t2?-r[j]:r[j])-c;
				if(x[j]==0){
					double b = E / y[j];
					double a1 = sqrt(1-b*b);
					double a2 = -a1;

					ang[pos++]=go(i,j,a1,b,c);
					ang[pos++]=go(i,j,a2,b,c);
				}else{
					double A = E/x[j];
					double B = -y[j]/double(x[j]);

					double k1 = B*B+1;
					double k2 = 2*A*B;
					double k3 = A*A-1;
					double D = k2*k2-4*k1*k3;
					D = sqrt(D);

					double b1 = (-k2-D)/2/k1;
					double b2 = (-k2+D)/2/k1;
					double a1 = A+B*b1;
					double a2 = A+B*b2;

					ang[pos++]=go(i,j,a1,b1,c);
					ang[pos++]=go(i,j,a2,b2,c);
				}
			}
			sort(ang,ang+pos);
			ang[pos]=ang[0]+2*pi;
			//REP(k,9) cout<<ang[k]<<' ';puts("");
			FOR(k,1,pos+1){
				double s =(ang[k-1]+ang[k])/2;
				if(good(i,j,s)){
					add(v, ang[k-1],ang[k], j);
					//cout<<ang[i-1]<<' '<<ang[i]<<endl;
				}
			}
		}

		REP(j,n)if(i!=j)x[j]+=x[i],y[j]+=y[i];
		SORT(v);
		int cnt=1,z=1;
		REP(j,v.size()){
			if(v[j].second>=0) cnt++;
			else cnt--;
			z=max(z,cnt);
		}
		//cout<<i<<": "<<z<<endl;
		res = max(res, z);
	}
	return res;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
#endif

	ll k;
	cin>>n>>k;
	REP(i,n) scanf("%d %d %d",x+i,y+i,r+i);
	cout<<n+(2*solve()+k-1)*k/2<<endl;


#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}