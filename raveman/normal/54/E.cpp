#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include<complex>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<pii,int> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int n;
int x[111111],y[111111];

double s(int i,int j,int k){
        return fabs(0.+(x[j]-x[i])*ll(y[k]-y[i])-(x[k]-x[i])*ll(y[j]-y[i]))/2.;
}

double dist(int i,int j,int k){
        double dx = x[j] - x[i];
        double dy = y[j] - y[i];

        double v = (x[k] - x[j]) * dx + (y[k] - y[j]) * dy;

        if(v < 0) return 0;
        return v / hypot(dx,dy);
}

double solve(){
        int p1 = 1;
        double sq = 0;
        double res = 1e100;
        REP(i,n){
                int a = i;
                int b = i+1;

                while(dist(a,b,p1) < dist(a,b,p1+1)){
                        sq += s(b, p1, p1+1);
                        p1++;
                }

                
                if(p1 == b) return 0.;

                double d = hypot(x[b] - x[p1], y[b] - y[p1]);
                double v = dist(a,b, p1);

                double c = sqrt(d*d - v*v);

                res = min(res, c*v/2 - sq);
                if(res<0.7)
                        res=res;

                sq -= s(b, b+1, p1);

        }
        return res;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
 ///   freopen("output.txt","w",stdout);
#endif

    cin>>n;
    REP(i,n) scanf("%d %d",x+i,y+i);
    REP(i,n) x[i+n] = x[i],y[i+n]=y[i];

    double res = 1e100;
    res = min(res ,solve());
    reverse(x,x+2*n);
    reverse(y,y+2*n);
    res=min(res,solve());

    printf("%.10lf\n",res);

    return 0;
}