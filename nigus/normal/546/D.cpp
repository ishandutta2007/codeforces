#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

std::vector<ll> prim;
std::vector<ll> R;
ll lprim;
ll coun;
ll rek(ll n){


    //cout << n << "\n";
    if(coun>n){return R[n];}

if(n==1){return 0;}
else{

    ll x,d1,y;
    x=0ll;
    for(d1=0;d1<lprim;d1++){
        if(n%prim[d1]==0){

                if(prim[d1] == n){R[n] = 1ll;return R[n];}

                x=prim[d1];y = R[round(n/x)];R[n] = y+1;return R[n];
                break;

                }



    }
R[n]=1;
return R[n];


}



}

int main()
{
    ll t,n,lim,a,b;
    int c1,c2,c3,c4;
    ///////////////////
    lim = ceil(sqrt(5000000))+6;
    lprim=0;
    for(c1=2;c1<lim;c1++){
        for(c2=2;c2<=c1;c2++){
            if(c1%c2==0){

                if(c1==c2){prim.push_back(c1);lprim++;}
                break;

            }


        }

    }

    for(c1=0;c1<5000002;c1++){R.push_back(0);}

    std::vector<ll> R2;
    R2.push_back(0);
    R2.push_back(0);
    for(c1=2;c1<5000002;c1++){
        coun=c1;
        a=rek(c1);
        R2.push_back(R2[c1-1]+a);
        //cout << a << "\n";

    }

    //////////////////
    //cout << "FDS\n";
    std::cin >> t;
    for(c1=0;c1<t;c1++){

        scanf("%d",&a);
        scanf("%d",&b);
        printf("%d\n",R2[a]-R2[b]);






    }



   return 0;
}