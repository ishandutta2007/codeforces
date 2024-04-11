#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int main()
{
    ll n,k1,k2,a,b,f,c;
    int c1,c2,c3,c4;
    ll lim = 40000000;
    int fail=0;

    std::queue<ll> p1;
    std::queue<ll> p2;

    std::cin >> n;

    std::cin >> k1;

    for(c1=0;c1 < k1;c1++){std::cin >> a; p1.push(a);}

    std::cin >> k2;

    for(c1=0;c1 < k2;c1++){std::cin >> a; p2.push(a);}

    f=0;
    c=0;
    while(k1!=0 && k2!=0){

        c++;
        a=p1.front();
        b=p2.front();
        p1.pop();
        p2.pop();
        if(a>b){

            f++;
            p1.push(b);
            p1.push(a);
            k1+=1;
            k2-=1;
        }
        else{

            f++;
            p2.push(a);
            p2.push(b);
            k2+=1;
            k1-=1;

        }

        if(c >= lim){fail=1;break;}

    }

    if(fail==1){std::cout << -1 << "\n";}
    else{

        if(k1==0){a=2;}
        else{a=1;}
        std::cout << f << " " <<a<<"\n";

    }



   return 0;
}