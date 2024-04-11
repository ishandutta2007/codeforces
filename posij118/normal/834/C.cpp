#include <bits/stdc++.h>
using namespace std;

long long int euclid(long long int a, long long int b){
    while(a>0 && b>0){
        if(a>b) a=a%b;
        else b=b%a;
    }

    return max(a, b);
}

int main(){
    int n, skap, dmez, hmez;
    long long int a, b;
    scanf("%d",&n);

    long long int cubes[1000000];
    for(long long int i=0; i<1000000; i++){
        cubes[i]=(i+1)*(i+1)*(i+1);
    }

    long long int sc[n][2];
    for(int i=0; i<n; i++){
        scanf("%lld%lld",&sc[i][0],&sc[i][1]);
        skap=0;
        a=(euclid(sc[i][0], sc[i][1])*euclid(sc[i][0], sc[i][1]));
        b=((sc[i][0]*sc[i][1])/euclid(sc[i][0], sc[i][1]));
        dmez=0;
        hmez=1000000;

        if(a%b!=0){
                printf("No\n");
                continue;
        }

        for(int j=0; j<35; j++){
            if((a/b)<cubes[(dmez+hmez)/2]) hmez=(dmez+hmez)/2;
            else if ((a/b)>cubes[(dmez+hmez)/2]) dmez=(dmez+hmez)/2;
            else{
                skap=1;
            }
        }

        if(skap==1) printf("Yes\n");
        else printf("No\n");
    }

}