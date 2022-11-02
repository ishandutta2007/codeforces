#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, L, x;
    x=0;
    long long int ans, m;
    ans=0;
    cin >> n >> L;
    long long int an[30];
    fill(an, an + 30, 1000000000000000000);
    long long int c[n];
    for(int i=0; i<n; i++){
        cin >> c[i];
    }

    long long int pow[30];
    pow[0]=1;
    for(int i=1; i<30; i++){
        pow[i]=2*pow[i-1];
    }

    while(L>0){
        for(int i=n-1; i>-1; i--){
            if(pow[i]<=L){
                m=1000000000000000000;
                for(int j=0; j<=i; j++){
                    m=min(m, c[j]*pow[i-j]);
                }

                for(int j=i+1; j<n; j++){
                    an[x]=min(an[x], ans+c[j]);
                }

                ans+=m*(L/pow[i]);
                L%=pow[i];
            }
        }

        x++;
    }

    for(int i=0; i<30; i++){
        ans=min(ans, an[i]);
    }

    cout << ans;


}