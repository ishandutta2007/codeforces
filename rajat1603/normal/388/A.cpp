#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n;
int arr[N];
int ans = 0;
multiset < int > s;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        s.insert(arr[i]);
    }
    while(!s.empty()){
        ++ans;
        s.erase(s.begin());
        int cnt = 1;
        while(!s.empty()){
            auto it = s.lower_bound(cnt);
            if(it != s.end()){
                s.erase(it);
                ++cnt;
            }
            else{
                break;
            }
        }
    }
    printf("%d\n" , ans);
}