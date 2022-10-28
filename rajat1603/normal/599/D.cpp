#include "bits/stdc++.h"
using namespace std;
const unsigned long long N = 2e6;
unsigned long long x;
vector < pair < unsigned long long , unsigned long long > > ans;
int answer = 0;
unsigned long long getn(unsigned long long n){
    unsigned long long res = x * 6ULL;
    res += n * n * n;
    res -= n;
    return res;
}
unsigned long long getd(unsigned long long n){
    unsigned long long res = n * n;
    res += n;
    res *= 3ULL;
    return res;
}
int main(){
    cin >> x;
    for(unsigned n = 1 ; n <= N ; ++n){
        unsigned long long num = getn(n);
        unsigned long long den = getd(n);
        if(num % den){
            continue;
        }
        unsigned long long m = num / den;
        if(m < n){
            continue;
        }
        ++answer;
        if(n != m){
            ++answer;
        }
        ans.emplace_back(make_pair(n , m));
    }
    printf("%d\n" , answer);
    for(auto it : ans){
        printf("%llu %llu\n" , it.first , it.second);
    }
    reverse(ans.begin() , ans.end());
    for(auto it : ans){
        if(it.first != it.second){
            printf("%llu %llu\n" , it.second , it.first);
        }
    }
}