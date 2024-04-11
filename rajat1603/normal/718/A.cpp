#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , t;
char arr[N];
int decipt;
int mxidx;
char get(int idx){
    if(idx > mxidx){
        return '0';
    }
    if(idx == decipt){
        return arr[idx + 1];
    }
    return arr[idx];
}
void print(int start){
    int idx = -1;
    for(int i = mxidx + 1 ; i <= n ; ++i){
        arr[i] = '0';
    }
    arr[decipt] = '.';
    for(int i = n ; i >= start ; --i){
        if(arr[i] > '0' && arr[i] <= '9'){
            idx = i;
            break;
        }
    }
    if(decipt > idx){
        idx = decipt - 1;
    }
    for(int i = start ; i <= idx ; ++i){
        printf("%c" , arr[i]);
    }
}
int add(int idx){
    mxidx = idx;
    for(int i = idx ; i >= 1 ; --i){
        if(arr[i] == '.'){
            continue;
        }
        if(arr[i] < '9'){
            ++arr[i];
            return i;
        }
        arr[i] = '0';
    }
    arr[0] = '1';
    print(0);
    exit(0);
}
int main(){
    scanf("%d %d" , &n , &t);
    scanf("%s" , arr + 1);
    mxidx = n;
    for(int i = 1 ; i <= n ; ++i){
        if(arr[i] == '.'){
            decipt = i;
        }
    }
    if(arr[decipt + 1] >= '5'){
        int tmp = add(decipt - 1);
    }
    else{
        int idx = -1;
        for(int i = decipt + 1 ; i < n ; ++i){
            if(arr[i + 1] >= '5'){
                idx = i;
                break;
            }
        }
        if(idx != -1){
            int tmp = add(idx);
            --t;
            while(t >= 1){
                int tmpidx = idx;
                idx = -1;
                for(int j = tmp - 1 - (tmp - 1 == decipt); j < tmpidx ; ++j){
                    if(j == decipt){
                        continue;
                    }
                    if(j < decipt - 1){
                        continue;
                    }
                    if(get(j + 1) >= '5'){
                        idx = j;
                        break;
                    }
                }
                if(idx == -1){
                    break;
                }
                tmp = add(idx);
                --t;
            }
        }
    }
    print(1);
}