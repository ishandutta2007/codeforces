#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n;
char arr[N];
long long ans = 0;
int main(){
    scanf("%s" , arr);
    n = strlen(arr);
    for(int i = 0 ; i < n ; ++i){
        if((arr[i] - '0') % 4 == 0){
            ++ans;
        }
    }
    for(int i = 1 ; i < n ; ++i){
        if(((arr[i - 1] - '0') * 10 + (arr[i] - '0')) % 4 == 0){
            ans += i;
        }
    }
    cout << ans;
}