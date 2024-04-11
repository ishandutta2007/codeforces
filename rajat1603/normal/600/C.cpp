#include "bits/stdc++.h"
using namespace std;
string str;
int beech;
int cnt[26];
int main(){
    cin >> str;
    memset(cnt , 0 , sizeof(cnt));
    beech = -1;
    for(char c : str){
        ++cnt[c - 'a'];
    }
    for(int i = 0 ; i < 26 ; ++i){
        if(cnt[i] & 1){
            for(int j = 25 ; j > i ; --j){
                if(cnt[j] & 1){
                    ++cnt[i];
                    --cnt[j];
                    break;
                }
            }
        }
        if(cnt[i] & 1){
            beech = i;
        }
    }
    for(int i = 0 ; i < 26 ; ++i){
        int x = cnt[i] >> 1;
        cnt[i] >>= 1;
        while(x--){
            printf("%c" , i + 'a');
        }
    }
    if(beech != -1){
        printf("%c" , 'a' + beech);
    }
    for(int i = 25 ; i >= 0 ; --i){
        while(cnt[i]--){
            printf("%c" , i + 'a');   
        }
    }
}