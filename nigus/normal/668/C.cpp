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
#include <stdio.h>

using namespace std;
typedef long long ll;
typedef double ld;

ll big = 1000000007ll;

int n,m,k,q,d,h;
ll T;

std::vector<ld> A;
std::vector<ld> B;

std::vector<ld> P1;
std::vector<ld> P2;

ld eps = 0.00000000000000001;

ld zero(ld a){

if(abs(a) < eps){return ld(0);}
return a;
}

int main()
{
   ll c1,c2,c3,c4,c5,c6;
    ld x,y,z;
    ld a,b,c,e,t;
    ld da,db,dc,de;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    //cin >> n;
    scanf("%d" , &n);
    for(c1 = 0; c1 < n; c1++){
        //cin >> da;
        scanf("%lf" , &da);
        A.push_back(da);
    }
    for(c1 = 0; c1 < n; c1++){
        scanf("%lf" , &da);
        //cin >> da;
        B.push_back(da);
    }

    ld sa = ld(0);
    ld sb = ld(0);
   for(c1 = 0; c1 < n; c1++){
     a = A[c1];
     b = B[c1];
     ld g = (sa-a-b-sb)/ld(2);
     ld D = g*g + sa * (a+b) - a;
     //D = zero(D);
     if(D < 0){D = ld(0);}
     x = sqrt(D) - g;
     y = a+b-x;
     P1.push_back(x);
     P2.push_back(y);
     sa += x;
     sb += y;

   }

   for(c1 = 0 ;c1 < n; c1++){
    cout << setprecision(18) <<  P1[c1] << " ";
   }
   cout << "\n";
   for(c1 = 0 ;c1 < n; c1++){
    cout << setprecision(18) << P2[c1] << " ";
   }cout << "\n";

	return 0;
}