#pragma comment(linker, "/STACK:36777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
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

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,pii> p3i;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

const double eps = 1e-8;
double getDist(double startV,double a,double T){
    return startV*T+a*T*T/2;
}
double go(double d,double startV,double a,double v){
    double T = (v-startV)/a;

    double dist = getDist(startV,a,T);

    if(fabs(dist-d)<eps) return T;

    if(dist>d){
        double x = 0, y = T;
        REP(i,100){
            double s= (x+y)/2;

            dist = getDist(startV,a,s);

            if(dist>d) y = s;
            else x =s ;
        }
        return (x+y)/2;
    }else{
        return T+(d-dist)/v;
    }
}

double go2(double dist,double startV,double a,double v){
    double T = (v-startV)/a;

    double d = getDist(startV,a,T);
    if(d<=dist+eps){
        return T + (dist-d)/v;
    }else{
        double x =0 ,y=T;
        REP(i,100){
            double s = (x+y)/2;
            d = getDist(startV,a,s);
            if(d>dist) y=s;
            else x=s;
        }
        return (x+y)/2;
    }
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    double a,v,l,d,w;
    cin>>a>>v>>l>>d>>w;

    double res=0;

    if(v<=w+eps){
        res = go(l,0,a,v);
    }else{
        double T = sqrt((2 * d)/a);
        double V = a*T;

        double start =-1;

        if(V<=v+eps && V<=w+eps){
            res += T;
            start = V;
        }else{
            T = w/a;

            double lf = d - T*a*T/2;

            res= T;

            res += 2*go2(lf/2,w,a,v); 



            start = w;
        }

        res += go(l-d, start, a , v);
    }

    printf("%.10lf\n",res);
    
    return 0;
}