#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;
long long N;
int M;

map<long long, long long> vals;

long long solve(long long N);

long long ask(long long Q){
    if(!vals.count(Q)){
        vals[Q] = solve(Q);
        return vals[Q];
    }

    else return vals[Q];
}

long long solve(long long N){
    if (N < 0) return 0;
    else if(N < M) return 1;

    long long half = N/2;
    long long ret = 0;
    long long f, s;

    ret += ask(half) * ask(N - half);
    ret %= mod;

    for(int i = 1; i<M; i++){
        ret += ask(half - i) * ask(N - half - M + i);
        ret %= mod;
    }

    return ret;
}

int main(){
    cin >> N >> M;
    cout << solve(N);
}