#include "bits/stdc++.h"
using namespace std;
const int N = 2e4 + 4;
int n , m , p;
int x[N];
int y[N];
int dp[N];
int val[N];
int res1;
string res2;
void solve(int x1 , int y1 , int x2 , int y2){
    if(x1 == x2){
        res1 += (x[x1] + y[y1]) % p;
        for(int i = y1 + 1 ; i <= y2 ; ++i){
            res1 += (x[x1] + y[i]) % p;
            res2 += "S";
        }
        return;
    }
    if(y1 == y2){
        res1 += (x[x1] + y[y1]) % p;
        for(int i = x1 + 1 ; i <= x2 ; ++i){
            res1 += (x[i] + y[y1]) % p;
            res2 += "C";
        }
        return;
    }
    int mid = (x1 + y1 + x2 + y2) >> 1;
    for(int i = y1 ; i <= y2 ; ++i){
        dp[i] = 0;
    }
    for(int i = y1 ; i <= y2 ; ++i){
        val[i] = 0;
    }
    for(int i = x1 ; i <= x2 ; ++i){
        for(int j = y1 ; j <= min(y2 , mid - i) ; ++j){
            int &res = dp[j];
            if(j - 1 >= y1){
                res = max(res , dp[j - 1]);
            }
            int tmp = (x[i] + y[j]);
            if(tmp >= p){
                tmp -= p;
            }
            res += tmp;
            if(i + j == mid){
                val[j] += res;
            }
        }
    }
    for(int i = y1 ; i <= y2 ; ++i){
        dp[i] = 0;
    }
    for(int i = x2 ; i >= x1 ; --i){
        for(int j = y2 ; j >= max(y1 , mid - i) ; --j){
            int &res = dp[j];
            if(j + 1 <= y2){
                res = max(res , dp[j + 1]);
            }
            if(i + j == mid){
                val[j] += res;
            }
            int tmp = (x[i] + y[j]);
            if(tmp >= p){
                tmp -= p;
            }
            res += tmp;
        }
    }
    int mxi;
    int mxj;
    int mxval = -1;
    for(int i = max(y1 , mid - x2) ; i <= min(y2 , mid - x1) ; ++i){
        if(val[i] > mxval){
            mxval = val[i];
            mxi = mid - i;
            mxj = i;
        }
    }
    res1 -= (x[mxi] + y[mxj]) % p;
    solve(x1 , y1 , mxi , mxj);
    solve(mxi , mxj , x2 , y2);
}
int main(){
    scanf("%d %d %d" , &n , &m , &p);
    for(int i = 0 ; i < n ; ++i){
        scanf("%d" , x + i);
        x[i] %= p;
    }
    for(int i = 0 ; i < m ; ++i){
        scanf("%d" , y + i);
        y[i] %= p;
    }
    solve(0 , 0 , n - 1 , m - 1);
    printf("%d\n" , res1);
    for(char c : res2){
        printf("%c" , c);
    }
    printf("\n");
}