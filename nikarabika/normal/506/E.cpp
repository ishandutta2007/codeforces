#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define MOD 10007

int N;
string s;
int dp[210][210][210]; // L, R, diagonals

typedef vector <vector <int> > matrix;

matrix mat_prod(matrix &A, matrix &B){
    int N=A.size(),i,j,k;
    matrix C(N, vector <int> (N, 0));
    REP(i,N) REP(j,N){
        int tmp = 0;
        REP(k,N){
            tmp += A[i][k] * B[k][j];
            if((k&15) == 15) tmp %= MOD;
        }
        C[i][j] = tmp % MOD;
    }
    return C;
}

matrix mat_power(matrix &A, int K){
    int N=A.size(),i,j;
    matrix ans(N, vector <int> (N, 0));
    REP(i,N) ans[i][i] = 1;
    for(i=30;i>=0;i--) if(K&(1<<i)) break;
    for(;i>=0;i--){
        ans = mat_prod(ans, ans);
        if(K&(1<<i)) ans = mat_prod(ans, A);
    }
    return ans;
}

matrix A,B;

void pre(int K){
    int i;
    
    matrix C(310, vector <int> (310, 0));
    REP(i,309) C[i][i+1] = 1;
    REP(i,205) C[i][i] = 24;
    REP(i,105) C[205+i][205+i] = 25;
    A = mat_power(C, K);
    
    matrix D(311, vector <int> (311, 0));
    REP(i,310) D[i][i+1] = 1;
    REP(i,205) D[i][i] = 24;
    D[205][205] = 26;
    REP(i,105) D[206+i][206+i] = 25;
    B = mat_power(D, K);
}

int func2(int K, int moves, int stay24, int stay25, int stay26){
    if(stay26 == 0) return A[205-stay24][204+stay25];
    return B[205-stay24][205+stay25];
}

int func(int K, bool odd){
    int ans=0,i,j,k;
    
    REP(i,N+1) REP(j,N+1) if(i == j || i == j + 1 || (i == j - 1 && odd)){
        REP(k,210) if(dp[i][j][k] != 0){
            int moves = N - (j - i) - k;
            int stay25 = k;
            int stay24 = moves - k;
            int stay26 = 0;
            if(i >= j) stay26++; else stay25++;
            
            int tmp = func2(K, moves, stay24, stay25, stay26);
            if(odd && i >= j) tmp = tmp * 26 % MOD;
            ans = (ans + tmp * dp[i][j][k]) % MOD;
        }
    }
    
    return ans;
}

int main(void){
    int i,j,k,d;
    int K;
    
    cin >> s >> K;
    N = s.length();
    
    dp[0][N][0] = 1;
    for(d=N;d>=1;d--) REP(i,N-d+1){
        j = i + d;
        REP(k,210) if(dp[i][j][k] != 0){
            if(s[i] == s[j-1]){
                dp[i+1][j-1][k+1] = (dp[i+1][j-1][k+1] + dp[i][j][k]) % MOD;
            } else {
                dp[i+1][j][k] = (dp[i+1][j][k] + dp[i][j][k]) % MOD;
                dp[i][j-1][k] = (dp[i][j-1][k] + dp[i][j][k]) % MOD;
            }
        }
    }
    
    K += N;
    pre(K/2);
    int ans = func(K/2, (K % 2 == 1));
    cout << ans << endl;
    
    return 0;
}