#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , m;
int arr[N];
set < int > even;
set < int > odd;
map < int , int > ev;
map < int , int > od;
int ans;
int geteven(){
    if(even.empty()){
        printf("-1\n");
        exit(0);
    }
    int ret = *even.begin();
    even.erase(even.begin());
    return ret;
}
int getodd(){
    if(odd.empty()){
        printf("-1\n");
        exit(0);
    }
    int ret = *odd.begin();
    odd.erase(odd.begin());
    return ret;
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    for(int i = 1 ; i <= min(m , 2 * N) ; ++i){
        if(i & 1){
            odd.insert(i);
        }
        else{
            even.insert(i);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(odd.find(arr[i]) != odd.end()){
            odd.erase(odd.find(arr[i]));
        }
        if(even.find(arr[i]) != even.end()){
            even.erase(even.find(arr[i]));
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(arr[i] & 1){
            ++od[arr[i]];
        }
        else{
            ++ev[arr[i]];
        }
    }
    int oc = od.size();
    int ec = ev.size();
    od.clear();
    ev.clear();
    for(int i = 1 ; i <= n ; ++i){
        if(arr[i] & 1){
            ++od[arr[i]];
            if(od[arr[i]] > 1){
                if(oc > ec){
                    int x = geteven();
                    arr[i] = x;
                    ++ans;
                    ++ec;
                }
                else{
                    int x = getodd();
                    arr[i] = x;
                    ++ans;
                    ++oc;
                }
            }
        }
        else{
            ++ev[arr[i]];
            if(ev[arr[i]] > 1){
                if(oc >= ec){
                    int x = geteven();
                    arr[i] = x;
                    ++ans;
                    ++ec;
                }
                else{
                    int x = getodd();
                    arr[i] = x;
                    ++ans;
                    ++oc;
                }
            }   
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(oc > ec && (arr[i] & 1)){
            arr[i] = geteven();
            ++ans;
            ++ec;
            --oc;
        }
        if(ec > oc && (!(arr[i] & 1))){
            arr[i] = getodd();
            ++ans;
            ++oc;
            --ec;
        }
    }
    printf("%d\n" , ans);
    for(int i = 1 ; i <= n ; ++i){
        printf("%d%c" , arr[i] , " \n"[i == n]);
    }
}