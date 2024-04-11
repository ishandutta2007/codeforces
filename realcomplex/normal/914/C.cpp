#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define abs(a) ((a<0) ? -a : a)
#define pii pair<int,int>
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int N = (int)1009;
const int MOD = (int)1e9 + 7;
int combinations[N][N];
int f[N];

void init(){
    for(int i = 2;i<N;i++)
        f[i]=f[_ones(i)]+1;
    for(int i = 0;i<N;i++)combinations[i][0]=1;
    for(int i = 1;i<N;i++)
        for(int j = 1;j<N;j++)
            combinations[i][j]=(combinations[i-1][j]+combinations[i-1][j-1])%MOD;
}

int main(){
    init();
    string a;
    int k,n;
    cin >> a >> k;
    n = a.size();
    if(k==0){
        cout << 1 << "\n";
        return 0;
    }
    if(k==1){
        cout << n-1;
        return 0;
    }

    int left_ones = 0;
    int ans = 0;
    for(int i = 0;i<a.size();i++){
        if(a[i]=='0'){
            continue;
        }
        for(int j = max(left_ones,2);j<N;j++){//we should choose j-left_ones bits from range [I..N)
            if(f[j]!=k-1)continue;
            if(j-left_ones<0)continue;
            ans += combinations[n-i-1][j-left_ones];
            ans %= MOD;
        }
        left_ones++;
    }
    if(f[left_ones]==k-1)ans++;
    cout << ans <<"\n";
    return 0;
}