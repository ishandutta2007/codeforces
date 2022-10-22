#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

using namespace std;
typedef long long ll;

ll big = 1000000007ll;
ll bp = 1168195727ll;

std::vector<double> A;
std::vector<double> M;
ll T;
    double a,b,c,d;
    ll n;
    ll x,y,z,w,k;

double ma(double r, double t)
{

    if(r>t){return r;}else{return t;}


}

double kad(double x)
{

    ll c1;

    double mg=0.0;
    double mg2=0.0;
    M[0]=ma(0,A[0]-x);
    mg=M[0];
    for(c1=1;c1<n;c1++)
    {
        M[c1]=ma(0,M[c1-1]+A[c1]-x);
        if(M[c1]>mg){mg=M[c1];}

    }

    M[0]=ma(0,-A[0]+x);
    mg2=M[0];
    for(c1=1;c1<n;c1++)
    {
        M[c1]=ma(0,M[c1-1]-A[c1]+x);
        if(M[c1]>mg2){mg2=M[c1];}

    }
//if(1==1){cout <<x << " " <<  mg << " " << mg2 << "\n";}
    return ma(mg,mg2);


}

int main()
{
    ll c1,c2,c3,c4,c5,c6;


    std::cin >> n;




for(c1=0;c1<n;c1++)
{

    std::cin >> x;
    A.push_back(double(x));


    M.push_back(0.0);

}


a=-10001.0;
double dum=kad(-10001.0);
b=10001.0;
double C,D;
double ans;
ll coun=0;
while(coun < 100)
{
  c=a+double(b-a)/3.0;
  d=a+2.0*double(b-a)/3.0;
C=kad(c);
D=kad(d);

coun++;

if(C>D){a=c;}
else{b=d;}


}

if(dum<kad(c)){ans=-10001.0;}else{ans=c;}
//std::cout << ans << "\n";
ans=kad(ans);
std::cout <<std::setprecision(18)<< ans << "\n";






    return 0;
}