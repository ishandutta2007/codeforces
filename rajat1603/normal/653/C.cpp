#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int arr[N];
set < int > idx;
long long ans = 0;
int compute(int x , int y , int val , int a , int b , int c = 0){
    for(int i = 1 ; i <= n ; ++i){
        if(i == a){
            continue;
        }
        if(i == b){
            continue;
        }
        if(i == c){
            continue;
        }
        if(arr[i] > y || arr[i] < x){
            continue;
        }
        int x1 , x2;
        if(i & 1){
            x1 = 0;
            x2 = min(arr[i - 1] , arr[i + 1]) - 1;
        }
        else{
            x2 = N - 1;
            x1 = max(arr[i - 1] , arr[i + 1]) + 1;
        }
        ans += (val >= x1 && val <= x2);
    }
}
int valid(){
    for(int i = 1 ; i < n ; ++i){
        if(i & 1){
            if(arr[i + 1] <= arr[i]){
                return 0;
            }
        }
        else{
            if(arr[i + 1] >= arr[i]){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    arr[0] = N - 1;
    arr[n + 1] = (n & 1) * (N - 1);
    for(int i = 1 ; i < n ; ++i){
        if(i & 1){
            if(arr[i + 1] <= arr[i]){
                idx.insert(i + 1);
                idx.insert(i);
            }
        }
        else{
            if(arr[i + 1] >= arr[i]){
                idx.insert(i + 1);
                idx.insert(i);
            }
        }
    }
    if(idx.size() > 6){
        printf("0\n");
        return 0;
    }
    if(idx.size() > 2){
        vector < int > vv;
        for(int x : idx){
            vv.emplace_back(x);
        }
        for(int i = 0 ; i < vv.size() ; ++i){
            for(int j = i + 1 ; j < vv.size() ; ++j){
                swap(arr[vv[i]] , arr[vv[j]]);
                ans += valid();
                swap(arr[vv[i]] , arr[vv[j]]);
            }
        }
        if(idx.size() <= 3){
            if(vv[1] & 1){
                compute(0 , min(arr[vv[0]] , arr[vv[2]]) - 1 , arr[vv[1]] , vv[0] , vv[1] , vv[2]);
            }
            else{
                compute(max(arr[vv[0]] , arr[vv[2]]) + 1 , N - 1 , arr[vv[1]] , vv[0] , vv[1] , vv[2]);
            }
        }
    }
    else{
        int a = *idx.begin();
        int b = *next(idx.begin());
        ans += (arr[a] != arr[b]);
        if(a & 1){
            compute(0 , arr[b] - 1 , arr[a] , a , b);
            compute(arr[a] + 1 , N - 1 , arr[b] , a , b);    
        }
        else{
            compute(arr[b] + 1 , N - 1 , arr[a] , a , b);
            compute(0 , arr[a] - 1 , arr[b] , a , b);
        }
    }
    printf("%lld\n" , ans);
}