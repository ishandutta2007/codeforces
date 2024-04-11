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

std::map<int,int> N;
std::map<int,int> M;
std::vector<int> M2;
std::vector<int> M3;
std::vector<ll> C;
ll ma=0;

int test(int x){


if(M3[x] >0){return M3[x];}
int b = x;
int mx=0;
while(b+x <= ma){

    b+=x;
    if(M2[b]>0){

       int t = test(b);
        if(t > mx){mx=t;}

    }

}

M3[x] = mx+M2[x];
return mx+M2[x];


}

int main()
{
	ll  z, m, b, c,l;
	ll c1, c2, c3, c4, c5, c6, c7;
    int a;
    int n;


    scanf("%d",&n);
    //n=100000;
    //std::cin >> n;


    for(c1=0;c1<1000003;c1++){M2.push_back(0);M3.push_back(0);}



    for(c1=0;c1<n;c1++){

        scanf("%d",&a);
        //a=c1+1;


        //std::cin >> a;
        C.push_back(a);
        if(a>ma){ma=a;}

        M2[a]++;

    }






std::sort(C.begin(),C.end());


int ans = 0;
int temp;
int k=0;
for(c1=0;c1<n;c1++){

    if(C[c1]!=1 && C[c1] != k){
    temp=test(C[c1]);

    if(temp>ans){ans=temp;}
    k=C[c1];
    }


}


ans+=M2[1];
//printf("%d \n",&ans);
std::cout << ans << "\n";
	return 0;
}