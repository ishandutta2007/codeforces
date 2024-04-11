#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
const int M = 61;
int n;
int arr[N];
int val[M] = {0 , 1 , 1 , 2 , 2 , 2 , 3 , 3 , 3 , 3 , 4 , 4 , 4 , 4 , 4 , 5 , 5 , 5 , 5 , 5 , 5 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 9 , 9 , 9 , 9 , 9 , 9 , 9 , 9 , 9 , 9 , 10 , 10 , 10 , 10 , 10 , 10};
/*map < long long , int > mp[M];
int get(int val , long long mask){
    if(val == 0){
        return 0;
    }
    if(mp[val].find(mask) != mp[val].end()){
        return mp[val][mask];
    }
    long long lol = 0;
    for(int i = 1 ; i <= val ; ++i){
        if(!((mask >> i) & 1)){
            long long v = get(val - i , mask | (1LL << i));
            if(v <= 61){
                lol |= 1LL << v;
            }
        }
    }
    int res;
    for(int i = 0 ; i <= val ; ++i){
        if(!((lol >> i) & 1)){
            res = i;
            break;
        }
    }
    return mp[val][mask] = res;
}
void pre(){
    for(int i = 0 ; i < M ; ++i){
        val[i] = get(i , 0LL);
        cout << val[i] << " , ";
    }
    exit(0);
}*/
int main(){
    //pre();
    int ans = 0;
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        ans ^= val[arr[i]];
    }
    if(ans){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
}