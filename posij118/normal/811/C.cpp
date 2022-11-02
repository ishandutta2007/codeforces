#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);

    int n, skap, aor, yor, zor, b;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int cisla[5001];
    for(int i=0; i<5001; i++){
        cisla[i]=0;
    }

    for(int i=0; i<n; i++){
        cisla[a[i]]++;
    }

    int dp[n];

    for(int i=0; i<n; i++){
        dp[i]=0;
    }
    int pocet[5001];


    for(int i=0; i<n; i++){

        if(i>0) dp[i]=dp[i-1];

        for(int i=0; i<5001; i++){
        pocet[i]=0;
        }
        skap=0;
        aor=0;

        for(int j=i; j>-1; j--){

            pocet[a[j]]++;
            if(pocet[a[j]]==1){
                skap++;
                yor=a[j];
                zor=aor;
                aor=0;
                b=1;

                while(zor+yor>0){
                   aor+=b*((zor%2+yor%2)%2);
                   zor/=2;
                   yor/=2;
                   b*=2;
                }
            }

            if(pocet[a[j]]==cisla[a[j]]) skap--;

            if(skap==0 && j==0){
                dp[i]=max(dp[i], aor);
            }

            if(skap==0 && j>0){
                dp[i]=max(dp[i], dp[j-1]+aor);
            }
        }
    }

    cout << dp[n-1];

}