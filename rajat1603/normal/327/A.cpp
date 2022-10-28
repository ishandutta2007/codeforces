#include "bits/stdc++.h"
using namespace std;
const int N = 1 << 7;
int n;
bool inp;
int sum = 0;
int mx = -N;
int tot = 0;
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> inp;
        tot += inp;
        sum += inp ? -1 : 1;
        mx = max(mx , sum);
        if(sum < 0){
            sum = 0;
        }
    }
    cout << tot + mx;
}