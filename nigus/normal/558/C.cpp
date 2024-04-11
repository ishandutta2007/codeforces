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
std::map<ll,ll> U;
std::map<ll,ll> N;



int main()
{
	ll k, z, n, m, a, b, c;
	int c1, c2, c3, c4, c5, c6, c7;
	std::vector<ll> v;
	std::map<ll,ll> U;
	std::cin >> n;

    for(c1=0;c1<n;c1++){

        std::cin >> a;
        v.push_back(a);



    }

    for(c1=1;c1<100001;c1+=2){

        c2=1;
        c3=0;
        while(c1*c2 < 100001){

            U[c1*c2]=c1;
            N[c1*c2]=c3;

            c3++;
            c2*=2;
        }
    }
    U[0] = 0;
    N[0] = 0;

    std::vector<ll> h;
    std::make_heap(h.begin(),h.end());
    ll minu = 9999999;
    for(c1=0;c1<n;c1++){

        a=U[v[c1]] * 1000000 + v[c1];
        if(U[v[c1]] <minu){minu=U[v[c1]];}
        h.push_back(a);
        std::push_heap(h.begin(),h.end());


    }
    ll ans=0;

    while(minu!=round((h.front()-h.front()%1000000)/1000000)){

        a=h.front();
        std::pop_heap(h.begin(),h.end());
        h.pop_back();

        b=round((a-a%1000000)/1000000);
        z=floor(b/2);
        c=U[z];
        if(c<minu){minu=c;}

        h.push_back(c*1000000+z);
        std::push_heap(h.begin(),h.end());

        ans+=N[a%1000000]+1;
        //cout << a%1000000 << " " << N[a%1000000] << "\n";


    }

    for(c1=0;c1<n;c1++){
        k = h.front();
        v[c1] = round((k%1000000)/minu);
        std::pop_heap(h.begin(),h.end());
        h.pop_back();
        //cout << v[c1] << " ";

    }
   // cout<<"\n"<< minu << "\n";
    std::map<ll,ll> T;
    T[0] = 0;
    c2=1;
    for(c1=1;c1<1000000;c1*=2){

       T[c1] = c2;c2++;



    }
    ll ans2;
    ll mi = 99999999;
    for(c1=0;c1<=50;c1++){
        ans2=0;
        for(c2=0;c2<n;c2++){

            ans2+=abs(T[v[c2]]-c1);


        }
        //cout << c1 << " " << ans2 << "\n";
        if(ans2 <mi){mi=ans2;}



    }
//cout << mi << "\n";
std::cout << ans+mi << "\n";

	return 0;
}