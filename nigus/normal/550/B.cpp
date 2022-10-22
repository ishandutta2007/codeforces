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

ll n,l,r,x,a,b;
std::vector<ll> c;
ll ans;
int on[16];
void rek(int y){


if(y==n){
    ll mi=n-1;
    ll ma = 0;

    ll s=0;
    int d;
   for(d=0;d<n;d++){

       // if(on[d] == 1){cout << "1 ";}else{cout << "0 ";}



    if(on[d] == 1){s+=c[d];
    if(mi==n-1){mi=d;}
    ma=d;


    }

   }

   //cout << "\n";

   if(c[ma]-c[mi] >= x && s >= l && s <= r){ans++;}

}
else{
on[y]=0;
rek(y+1);
on[y]=1;
rek(y+1);
}



return;

}

int main()
{

    int c1,c2,c3,c4;

    std::cin >> n>>l>>r>>x;
    for(c1=0;c1<n;c1++){
        std::cin >> a;
        on[c1]=0;
        c.push_back(a);
    }

    std::sort(c.begin(),c.end());
    ans=0;
    rek(0);
    std::cout << ans << "\n";



   return 0;
}