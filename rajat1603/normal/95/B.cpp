#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
char str[N];
int n;
char res[N];
int nxt[N][10];
bool check(int l , int r , int cnt7 , int cnt4){
    int end7 = l + cnt7 - 1;
    int ql , qh;
    qh = n;
    ql = n;
    for(int i = 0 ; i < 7 ; ++i){
        if(nxt[l][i] <= end7){
            ql = min(ql , nxt[l][i]);
        }
    }
    for(int i = 0 ; i < 4 ; ++i){
        ql = min(ql , nxt[l][i]);
    }
    for(int i = 8 ; i < 10 ; ++i){
        qh = min(qh , nxt[l][i]);
    }
    for(int i = 5 ; i < 10 ; ++i){
        qh = min(qh , nxt[end7 + 1][i]);
    }
    return ql <= qh;
}
int main(){
    scanf("%s" , str);
    n = strlen(str);
    if(n & 1){
        ++n;
        for(int i = 0 ; i < n ; ++i){
            if(i + i < n){
                printf("4");
            }
            else{
                printf("7");
            }
        }
        return 0;
    }
    for(int i = 0 ; i < n ; ++i){
        if(i + i < n){
            res[i] = '7';
        }
        else{
            res[i] = '4';
        }
    }
    bool ok = 1;
    for(int i = 0 ; i < n ; ++i){
        if(str[i] < res[i]){
            break;
        }
        if(str[i] > res[i]){
            ok = 0;
            break;
        }
    }
    if(!ok){
        n += 2;
        for(int i = 0 ; i < n ; ++i){
            if(i + i < n){
                printf("4");
            }
            else{
                printf("7");
            }
        }
        return 0;
    }
    for(int i = 0 ; i < 10 ; ++i){
        nxt[n][i] = n;
    }
    for(int i = n - 1 ; i >= 0 ; --i){
        for(int j = 0 ; j < 10 ; ++j){
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][str[i] - '0'] = i;
    }
    ok = 0;
    int cnt7 = n >> 1;
    int cnt4 = n >> 1;
    for(int i = 0 ; i < n ; ++i){
        if(ok){
            if(cnt4){
                res[i] = '4';
                --cnt4;
            }
            else{
                res[i] = '7';
                --cnt7;
            }
        }
        else{
            if(str[i] < '4'){
                ok = 1;
                if(cnt4){
                    res[i] = '4';
                    --cnt4;
                }
                else{
                    res[i] = '7';
                    --cnt7;
                }
            }
            else if(str[i] == '4'){
                if(cnt4 && check(i + 1 , n + n - 1 , cnt7 , cnt4 - 1)){
                    res[i] = '4';
                    --cnt4;
                }
                else{
                    res[i] = '7';
                    --cnt7;
                    ok = 1;
                }
            }
            else if(str[i] < '7'){
                res[i] = '7';
                --cnt7;
                ok = 1;
            }
            else if(str[i] == '7'){
                --cnt7;
                res[i] = '7';
            }
        }
    }
    res[n + n] = '\0';
    printf("%s" , res);
}