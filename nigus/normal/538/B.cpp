#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <set>


using namespace std;

std::vector<int> qb;
std::vector<int> r;

std::vector<int> S;

std::vector<int> svar;

int x[1000001];
int mi[1000001];
int c[1000001];
int d[1000001];
int l;
int n;

int dp(int m){



if(r[m]!=0){return r[m];}


mi[m]=m+1;

for(c[m]=1;c[m]<l;c[m]++){

    d[m]=l-c[m];

    if(m-qb[d[m]] > 0){x[m]=dp(m-qb[d[m]]);

    if(x[m]<mi[m]){mi[m]=x[m];S[m]=qb[d[m]];}

    }



}

r[m]=mi[m]+1;
return r[m];



}


int main()
{

   int c1,c2,c3,c4,c5,c6,c7;
   int x;



   std::cin >> n;

   for(c1=0;c1<1000000;c1++){r.push_back(0);S.push_back(0);}

   for(c2=0;c2<=1;c2++){for(c3=0;c3<=1;c3++){for(c4=0;c4<=1;c4++){for(c5=0;c5<=1;c5++){for(c6=0;c6<=1;c6++){

    for(c7=0;c7<=1;c7++){

        x=100000*c2+10000*c3+1000*c4+100*c5+10*c6+c7;
        qb.push_back(x);
        r[x]=1;
        S[x]=x;

    }

   }}}}}
   qb.push_back(1000000);
   r[1000000]=1;
   S[1000000]=1000000;
   l=qb.size();

   x=dp(n);
   std::cout << x << "\n";
   c2=n;
   for(c1=0;c1<x-1;c1++){std::cout << S[c2] << " ";c2-=S[c2];}
   std::cout << S[c2] << "\n";



    return 0;
}