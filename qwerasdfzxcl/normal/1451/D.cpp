#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        double d;
        ll k;
        scanf("%lf %lld", &d, &k);
        double tmp=d*d/2;
        tmp=sqrt(tmp);
        ll mn=tmp;
        mn -= mn%k;
        //printf("%d\n", mn);
        if (mn*mn+(mn+k)*(mn+k)<=d*d) printf("Ashish\n");
        else printf("Utkarsh\n");
    }
    return 0;
}