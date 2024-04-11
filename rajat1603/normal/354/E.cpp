#include "bits/stdc++.h"
using namespace std;
const int LN = 19;
const int CMAX = 5;
int t;
string n;
int dp[LN][CMAX];
bool solve(int pos , int carry){
    if(pos < 0){
        return !carry;
    }
    if(dp[pos][carry] != -1){
        return dp[pos][carry];
    }
    bool res = 0;
    int dig = n[pos] - '0';
    for(int zero = 0 ; zero <= 6 ; ++zero){
        for(int four = 0 ; four + zero <= 6 ; ++four){
            int seven = 6 - four - zero;
            int val = four * 4 + seven * 7 + carry;
            if(val % 10 == dig){
                if(solve(pos - 1 , val / 10)){
                    res = 1;
                    zero = 7;
                    break;
                }
            }
        }
    }
    return dp[pos][carry] = res;
}
void go(){
    int carry = 0;
    long long cur = 1;
    vector < long long > v(6 , 0);
    for(int pos = n.size() - 1 ; pos >= 0 ; --pos){
        int zc;
        int fc;
        int sc;
        int dig = n[pos] - '0';
        for(int zero = 0 ; zero <= 6 ; ++zero){
            for(int four = 0 ; four + zero <= 6 ; ++four){
                int seven = 6 - four - zero;
                int val = four * 4 + seven * 7 + carry;
                if(val % 10 == dig){
                    if(solve(pos - 1 , val / 10)){
                        zc = zero;
                        fc = four;
                        sc = seven;
                        carry = val / 10;
                        zero = 7;
                        break;
                    }
                }
            }
        }
        for(int i = zc ; i < zc + fc ; ++i){
            v[i] += 4LL * cur;
        }
        for(int i = zc + fc ; i < zc + fc + sc ; ++i){
            v[i] += 7LL * cur;
        }
        cur *= 10;
    }
    for(int i = 0 ; i < 6 ; ++i){
        printf("%lld%c" , v[i] , " \n"[i == 5]);
    }
}
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        memset(dp , -1 , sizeof(dp));
        if(solve(n.size() - 1 , 0)){
            go();
        }
        else{
            printf("-1\n");
        }
    }
}