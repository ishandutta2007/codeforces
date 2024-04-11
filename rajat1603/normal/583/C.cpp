#include "bits/stdc++.h"
using namespace std;
multiset < int > ms;
int n , inp;
vector < int > v;
int main() {
    scanf("%d" , &n);;
    for(int i = 1 ; i <= n * n ; ++i){
        scanf("%d" , &inp);
        ms.insert(inp);
    }
    for(int i = 1 ; i <= n ; ++i){
        auto it = ms.end();
        --it;
        inp = *it;
        ms.erase(ms.find(inp));
        for(int x : v){
            int temp = __gcd(inp , x);
            ms.erase(ms.find(temp));
            ms.erase(ms.find(temp));
        }
        v.push_back(inp);
    }
    for(int x : v){
        printf("%d " , x);
    }
}