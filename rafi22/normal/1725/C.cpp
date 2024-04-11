#include <cstdio>
#include <vector>

using namespace std;

const long long mod = 998244353;

long long mod_pow(long long x, long long exp) {
    if(exp == 0)
        return 1;
    long long result = mod_pow(x, exp / 2);
    result = (result * result) % mod;
    if(exp % 2 == 1)
        result = (result * x) % mod;
    return result;
}

long long inv(long long x) {
    return mod_pow(x, mod - 2);
}

int main() {
    int n; scanf("%d", &n);
    int m; scanf("%d", &m);
    vector<long long>D(n);
    for(long long &x : D)
        scanf("%lld", &x);
    
    long long total_sum = 0;
    for(long long x : D)
        total_sum += x;
    
    int pairs = 0;
    
    if(total_sum % 2 == 0) {
        long long my_sum = D[0];
        int r = 0;
        for(int l = 0; l < n; l++) {
            while(my_sum * 2 < total_sum) {
                r = (r + 1) % n;
                my_sum += D[r];
            }
            
            if(my_sum * 2 == total_sum)
                pairs++;
            my_sum -= D[l];
        }
    }
    
    pairs /= 2;
    
    int t = max(n, m);
    vector<long long>fact(t + 1, 1), inv_fact(t + 1);
    for(int i = 2; i <= t; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    inv_fact[t] = inv(fact[t]);
    for(int i = t - 1; i >= 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    
    
    long long answer = 0;
    
    for(int taken_pairs = 0; taken_pairs <= pairs; taken_pairs++) {
        
        long long remainder_colours = m - taken_pairs;
        long long remainder_pairs = pairs - taken_pairs;
        
        if(remainder_colours < 2 && remainder_pairs > 0)
            continue;
        
        if(remainder_colours < 1 && 2 * taken_pairs != n)
            continue;
        
        if(remainder_colours < 0)
            continue;
        
        long long choose_pairs = fact[pairs] * inv_fact[taken_pairs] % mod;
        choose_pairs = choose_pairs * inv_fact[pairs - taken_pairs] % mod;
        
        long long choose_pair_colours = fact[m] * inv_fact[m - taken_pairs] % mod;
        
        long long one_free_pair_choice = remainder_colours * (remainder_colours - 1) % mod;
        long long colours_remainder = mod_pow(one_free_pair_choice, remainder_pairs);
        
        long long free_colours = mod_pow(remainder_colours, n - 2 * pairs);
        
        
        long long to_add = choose_pairs * choose_pair_colours % mod;
        to_add = to_add * colours_remainder % mod;
        to_add = to_add * free_colours % mod;
        
        answer += to_add;
        answer %= mod;
    }
    
    printf("%lld\n", answer % mod);
    
    
    return 0;
}