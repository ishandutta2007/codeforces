#include <bits/stdc++.h>
using namespace std;
 
bool query(long long l, long long r){
    cout << l << " " << r << endl;
    string str;
    cin >> str;
    if(l==r && str=="Yes") exit(0);
    return (str == "Yes");
}
 
int main(){
    long long i, j, k;
    long long N, K;
    cin >> N >> K;
 
    const long long T = 50;
    mt19937_64 rnd;
    long long ub = N, lb = 1;
    while(true){
        while(ub-lb>4*K){
            long long mid = (ub+lb)/2;
            if(query(lb, mid)){
                lb = max(1LL, lb-K);
                ub = min(N, mid+K);
            }else{
                lb = max(1LL, mid+1-K);
                ub = min(N, ub+K);
            }
        }
        uniform_int_distribution<long long> dist(lb, ub);
        for(i=0; i<T; i++){
            long long x = dist(rnd);
            query(x, x);
        }
        lb = max(1LL, lb-(T+1)*K);
        ub = min(N, ub+(T+1)*K);
    }
}