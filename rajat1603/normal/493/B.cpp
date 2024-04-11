#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
vector < int > v1;
vector < int > v2;
int inp;
long long sum1 = 0;
long long sum2 = 0;
bool check(int pos){
    if(pos >= v1.size()){
        return 1;
    }
    if(pos >= v2.size()){
        return 0;
    }
    if(v1[pos] < v2[pos]){
        return 1;
    }
    if(v1[pos] > v2[pos]){
        return 0;
    }
    return check(pos + 1);
}
int main(){
    cin >> n;
    while(n--){
        cin >> inp;
        if(inp < 0){
            v2.emplace_back(-inp);
            sum2 -= inp;
        }
        else{
            v1.emplace_back(inp);
            sum1 += inp;
        }
    }
    if(sum1 > sum2){
        puts("first");
    }
    else if(sum1 < sum2){
        puts("second");
    }
    else{
        if(v1 == v2){
            puts((inp > 0) ? "first" : "second");
        }
        else{
            puts((check(0)) ? "second" : "first");
        }
    }
}