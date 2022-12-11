#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll croot(ll r){
    ll sak = 1;
    ll be = 1e6 + 1;
    ll mid;
    for(int i = 1e6 + 1;i>0;i/=2){
    	mid = (sak+be)/2;
        if(mid*mid*mid == r){
            return mid;
        }
        else{
            if(mid*mid*mid >= r){
                be = mid;
            }
            else{
                sak = mid;
            }
        }
    }
    return mid;
}

int main(){

    int n;
    scanf("%i",&n);
    ll a,b;
    ll cube;
    for(int i = 0;i<n;i++){
        scanf("%I64d %I64d",&a,&b);
        cube = croot(a*b);
        if(cube*cube*cube == a*b && b % cube == 0 && a % cube == 0){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}