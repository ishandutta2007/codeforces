#include <bits/stdc++.h>
using namespace std;

int xo(int a, int b){
    int res;
    int po;
    po=1;
    while(a>0 || b>0){
            res+=po*(a%2 ^ b%2);
            po*=2;
            a/=2;
            b/=2;
    }

}

int main(){
        ios::sync_with_stdio(false);
        int primes[19]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
        bool pri[19];
        int pr, c, xx;
        long long int x, y;
        int n, k;

        int M=1000000007;
        cin >> n;
        bool bin[19];
        int cnt[71];
        fill(cnt, cnt + 71, 0);
        int a[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
            cnt[a[i]]++;
        }

        int pow[max(1000, n+1)];
        pow[0]=1;
        for(int i=1; i<max(1000, n+1); i++){
            pow[i]=2*pow[i-1];
            pow[i]%=M;
        }

        vector<vector<int> > dp;
        vector<int> pos;
        dp.resize(71);
        for(int i=0; i<71; i++){
            dp[i].resize(pow[19]);
        }

        for(int i=0; i<71; i++){
            for(int j=0; j<pow[19]; j++){
                dp[i][j]=0;
            }
        }
        dp[0][0]=1;

        for(int i=1; i<71; i++){
            if(cnt[i]==0){
                for(int j=0; j<pow[19]; j++){
                    dp[i][j]=dp[i-1][j];
                }
                continue;
            }

            else{
                fill(pri, pri + 19, 0);
                for(int j=0; j<19; j++){
                    k=i;
                    while(k%primes[j]==0){
                        k/=primes[j];
                        pri[j]^=1;

                    }
                }
                pos.clear();

                for(int j=0; j<19; j++){
                    if(pri[j]==1) pos.push_back(j);
                }

                fill(bin, bin + 19, 0);
                for(int j=0; j<pow[19]; j++){

                    x=pow[cnt[i]-1];
                    y=x*dp[i-1][j];
                    y%=M;
                    xx=j;
                    for(int k=0; k<pos.size(); k++){
                        c=pos[k];
                        if((bin[c]==0)){
                            xx+=pow[c];
                        }
                        else xx-=pow[c];
                    }

                    dp[i][j]+=y;
                    dp[i][j]%=M;
                    dp[i][xx]+=y;
                    dp[i][xx]%=M;

                     for(int k=0; k<19; k++){
                        if(bin[k]==0){
                            bin[k]^=1;
                            for(int l=k-1; l>-1; l--){
                                bin[l]^=1;
                            }
                            break;
                        }
                    }


                }
            }
        }

        cout << dp[70][0]-1;

}