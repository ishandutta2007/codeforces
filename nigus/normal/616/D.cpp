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
int l, n,m,q,k;
std::vector<int> A;
std::vector<int> num;

int main()
{
    int a,b,c;
    ll c1,c2,c3,c4,c5;
    int t;
   // std::cin >> n >> k;
    scanf("%d %d",&n,&k);
    for(c1=0;c1<n;c1++){
        scanf("%d",&a);
        A.push_back(a);
    }
    for(c1=0;c1<1100000;c1++){
        num.push_back(0);
    }
    int ans = 0;
    int nu = 0;
    int l = 0;
    a = 0;
    b = 0;
    int a1=0;
    int a2=0;;
    while(b < n){
        num[A[b]]++;
        if(num[A[b]] == 1){nu++;l++;}
        while(nu>k){
            num[A[a]]--;
            if(num[A[a]] == 0){nu--;}
            a++;
            l--;
        }
        //cout << a << " " << b << " " << l << "\n";
        if((b-a) > ans){ans = b-a;a1=a;a2=b;}
        b++;
        l++;
    }
//std::cout << a1+1 <<" "<< a2+1;
printf("%d %d\n",a1+1,a2+1);


return 0;
}