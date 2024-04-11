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


int main()
{
	ll k, z, n, m, b, c,a;
	ll c1, c2, c3, c4, c5, c6, c7;
    std::cin >> n>>m>>k;
    std::vector<std::vector<ll> > A(n , std::vector<ll>());
    std::vector<std::vector<ll> > K(m , std::vector<ll>());
    std::vector<std::vector<ll> > K2(m , std::vector<ll>());
    std::vector<ll> B;
    ll h=1000000000ll;
    for(c1=0;c1<n;c1++){
        b=0;
        for(c2=0;c2<m;c2++){

            std::cin >> a;
            A[c1].push_back(a);
            b+=a;
        }
    B.push_back(b);
    }

    ll i,j,kt;
    i=0;
    j=0;


    for(c1=0;c1<m;c1++){

        std::make_heap(K[c1].begin(),K[c1].end());
        std::make_heap(K2[c1].begin(),K2[c1].end());


    }

    ll ma=-1;
    ll I,J;
    I=-1;
    J=-1;
    for(c1=0;c1<n;c1++){

        j=c1;
        b=0;
        for(c2=0;c2<m;c2++){

        K[c2].push_back(A[c1][c2]*h+c1);
        std::push_heap(K[c2].begin(),K[c2].end());

        K2[c2].push_back(-A[c1][c2]);
        std::push_heap(K2[c2].begin(),K2[c2].end());

        a=K[c2].front();
        b+=round((a-a%h)/h);

    }

    if(b>k){

        for(c2=i;c2<=j;c2++){

            b=0;
            for(c3=0;c3<m;c3++){


        while(1==1){
            if(K[c3].size()!=0){

            if(K[c3].front()%h<=c2){std::pop_heap(K[c3].begin(),K[c3].end());
        K[c3].pop_back();}else{break;}
            }else{break;}

        }





        if(K[c3].size()!=0){
        a=K[c3].front();
        b+=round((a-a%h)/h);}else{b+=0;}
        //cout << a << " "<<c2<<" "<<c3<<"\n";

    }

    if(b<=k){

        i=c2+1;
        break;

    }
            if(c2==j){i=j+1;}


        }


    }
    //std::cout << i << " " << j << "\n";
    if(j-i>ma){ma=j-i;I=i;J=j;}

    }

    //std::cout << I << " " << J;

    if(I==-1 || J==-1 || I>J){

        for(c1=0;c1<m-1;c1++){
            std::cout << 0 << " ";

        }std::cout << 0 << "\n";

    }
    else{

        std::vector<ll> ans;
        for(c1=0;c1<m;c1++){ans.push_back(0ll);}



        for(c1=I;c1<=J;c1++){

            for(c2=0;c2<m;c2++){

                   if(A[c1][c2] > ans[c2]){ans[c2]=A[c1][c2];}

            }




        }


        for(c1=0;c1<m-1;c1++){
            std::cout << ans[c1] << " ";

        }std::cout << ans[m-1] << "\n";


    }

	return 0;
}