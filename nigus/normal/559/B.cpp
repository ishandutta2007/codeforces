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

string A,B;
std::vector<ll> per;

bool test(ll a1,ll b1,ll a2,ll b2){
//cout << a1 << " "<< b1 << " "<< a2 << " " << b2<<"\n";

int c1;
ll l=b1-a1;
ll k= round(l/2);
   bool fail=0;
   bool yay=0;
   for(c1=l-1;c1>=0;c1--){
        //cout << "gfd";

    if(A[c1+a1] != B[c1+a2]){fail=1;break;}


   }
   if(fail==0){return 1;}
   if(l%2==0){

    int r1 = (int(A[l-1])+ l*l)%2;
    int r2 = (int(B[l-1])+ 2*l)%2;

    /*for(c1=0;c1<k;c1++){

        if(r1==0){s1+=a[c1];s3+=b[c1];}
        else{s3+=a[c1];s1+=b[c1];}


    }

    for(c1=k;c1<l;c1++){

        if(r2==0){s2+=a[c1];
        s4+=b[c1];}
        else{s4+=a[c1];
        s2+=b[c1];}


    }*/

    ll x1,x2,x3,x4,y1,y2,y3,y4;

    if(r1==0){x1=a1;x2=a1+k;x3=a1+k;x4=b1;}else{x1=a1+k;x2=b1;x3=a1;x4=a1+k;}
    if(r2==0){y1=a2;y2=a2+k;y3=a2+k;y4=b2;}else{y1=a2+k;y2=b2;y3=a2;y4=a2+k;}

    bool q1=test(x1,x2,y1,y2);
    bool p1,p2,q2;
    p2=0;
    p1=0;
    q2=0;



   if(q1==1){q2=test(x3,x4,y3,y4);}
   if(q2==1){p1=1;}
   if(p1!=1){

    q1=test(x1,x2,y3,y4);
    if(q1==1){
            q2=test(x3,x4,y1,y2);
    if(q2==1){p1=1;}

    }

   }



    if(p1==1){return 1;}else{return 0;}


   }


else{return 0;}




}

int main()
{
	ll k, z, n, m, b, c,a,l;
	ll c1, c2, c3, c4, c5, c6, c7;



   std::cin >> A >> B;
   l=A.length();
/*
   for(c1=0ll;c1<l;c1++){
    per.push_back(c1);
   }

for(c1=0;c1<(l*l)%2335;c1++){

    std::next_permutation(per.begin(),per.end());


}*/

   bool ans = test(0,l,0,l);

   if(ans==1){std::cout << "YES\n";}
   else{std::cout << "NO\n";}

	return 0;
}