#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef vector<int> VI;
typedef long long LL;

#define REP(i,n) for(int i=0; i<int(n); i++)

const LL MOD = 1000000007;

LL A, B;
int main() {
    cin >> A >> B;

    LL S = A*(A+1)/2 % MOD;
    LL T = B*(B-1)/2 % MOD;

    cout <<  (T * A + T * B % MOD * S) % MOD << endl;

    return 0;
}