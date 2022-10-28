#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , m;
int arr[N];
int type[N];
int val[N];
int res[N];
int suf[N];
int idx[N];
int cur = 0;
multiset < int > ms;
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        res[i] = arr[i];
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , type + i , val + i);
    }
    idx[++cur] = 0;
    val[0] = 0;
    for(int i = m ; i >= 1 ; --i){
        if(val[i] > suf[i + 1]){
            suf[i] = val[i];
            idx[++cur] = i;
        }
        else{
            suf[i] = suf[i + 1];
        }
    }
    for(int i = 1 ; i <= val[idx[cur]] ; ++i){
        ms.insert(arr[i]);
    }
    for(int i = cur ; i >= 2 ; --i){
        int a = val[idx[i]];
        int b = val[idx[i - 1]];
        for(int j = a ; j > b ; --j){
            if(type[idx[i]] == 1){
                res[j] = *prev(ms.end());
                ms.erase(prev(ms.end()));
            }
            else{
                res[j] = *ms.begin();
                ms.erase(ms.begin());
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        printf("%d " , res[i]);
    }
}