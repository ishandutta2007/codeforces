#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <iomanip>
#include <vector>
#define inf (1 << 30)
typedef long long ll;
using namespace std;

vector<int> pf(int n){
    vector<int> prime_factors;
    if(~n & 1){
        while(n % 2 == 0){
            n >>= 1;
        }
        prime_factors.push_back(2);
    }
    int i = 3;
    while(i * i <= n){
        if(n % i == 0){
            while(n % i == 0){
                n /= i;
            }
            prime_factors.push_back(i);
        }
        i += 2;
    }
    if(n != 1){
        prime_factors.push_back(n);
    }
    return prime_factors;
}

bool test(vector<int> diff, int rec){
    int each_size = diff.size() / rec;
    vector<int> init(each_size);
    for(int i=0;i<each_size;i++){
        init[i] = diff[i];
    }
    for(int i=1;i<rec;i++){
        for(int j=0;j<each_size;j++){
            if(diff[i*each_size+j] != init[j]){
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> S(50001);
int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        if(n == 2*abs(a-b)){
            S[n/2].push_back(a);
            S[n/2].push_back(b);
            continue;
        }
        if(a > b){swap(a,b);}
        if(abs(a-b) > n/2){
            a += n;
            S[a-b].push_back(b);
        }else{
            S[b-a].push_back(a);
        }
    }
    int k = n;
    for(int i=1;i<=n/2;i++){
        int gcd = n;
        vector<int> A = S[i];
        if(A.empty()){
            continue;
        }
        /*if(A.size()==1ULL){
            k = 1;
            break;
        }*/
        sort(A.begin(), A.end());
        vector<int> diff;
        for(int i=0;i<(int)A.size()-1;i++){
            diff.push_back(A[i+1]-A[i]);
        }
        diff.push_back(n + A.front()-A.back());
        gcd = __gcd(gcd, (int)diff.size());
        int rec = 1;
        for(auto i:pf(gcd)){
            int tester = i;
            while(test(diff, tester)){
                rec *= i;
                if(gcd / tester % i == 0){
                    tester *= i;
                }else{
                    break;
                }
            }
        }
        k = __gcd(k, rec);
    }
    if(k == 1){
        cout << "No";
    }else{
        cout << "Yes";
    }
    return 0;
}