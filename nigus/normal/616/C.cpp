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
ll big = 1000000007ll;
ll n,m,q,k;
std::vector<ll> C;
std::vector<ll> deg;
std::vector<ll> pek;
ll par(ll i){
    ll i2 = i;
    while(i2!=pek[i2]){
        i2=pek[i2];
    }
return i2;
}
void merg(ll i, ll j){
ll i2 = par(i);
ll j2 = par(j);
if(i2 != j2){
    if(deg[i2] > deg[j2]){
        pek[j2] = i2;
        deg[i2] += deg[j2];
    }
    else{
        pek[i2] = j2;
        deg[j2] += deg[i2];    }

}
return;
}
void check(ll i){
    ll a;
if(i % m != 0){
    a = i-1;
    if(C[a] == 0){merg(a,i);}
}
if((i+1) % m != 0){
    a = i+1;
    if(C[a] == 0){merg(a,i);}
}
if(i >= m){
    a = i-m;
    if(C[a] == 0){merg(a,i);}
}
if(i < m*(n-1)){
    a = i+m;
    if(C[a] == 0){merg(a,i);}
}
return;

}

ll check2(ll i){

std::vector<ll> A;
std::vector<ll> B;
ll c = 0;
ll ans = 0;
ll a;
if(i % m != 0){
    a = i-1;
    if(C[a] == 0){A.push_back(par(a));B.push_back(deg[par(a)]);c++;}
}
if((i+1) % m != 0){
    a = i+1;
    if(C[a] == 0){A.push_back(par(a));B.push_back(deg[par(a)]);c++;}
}
if(i >= m){
    a = i-m;
    if(C[a] == 0){A.push_back(par(a));B.push_back(deg[par(a)]);c++;}
}
if(i < m*(n-1)){
    a = i+m;
    if(C[a] == 0){A.push_back(par(a));B.push_back(deg[par(a)]);c++;}
}

for(ll j = 0; j < c; j++){
    for(ll q = j+1; q < c; q++){
        if(A[j] == A[q]){B[j] = 0;}
    }
}
for(ll r = 0; r < c; r++){
    ans += B[r];
}
return ans;


}
int main()
{
    ll a,b,c;
    ll c1,c2,c3,c4,c5;
    ll t;
    std::cin >> n >> m;
    string s;
    c3=0;
    for(c1 = 0; c1<n; c1++){
            std::cin >> s;
            for(c2 = 0; c2<m ; c2++){
                pek.push_back(c3);
                c3++;
                deg.push_back(1);
                if(s[c2] == '.'){
                    C.push_back(0);
                }
                else{
                    C.push_back(1);
                }
            }
    }

    for(c1 = 0; c1<n*m;c1++){
        if(C[c1] == 0){
           check(c1);
        }
    }

    for(c1 = 0; c1 < n*m;c1++){
        if(C[c1] == 1){a = check2(c1);printf("%d",(a+1)%10);//std::cout << (a+1)%10;
        }
        else{printf(".");}
        if((c1+1)%m == 0){//std::cout << "\n";
        printf("\n");}
    }



return 0;
}