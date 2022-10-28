#include "bits/stdc++.h"
using namespace std;
int n;
int t;
string str;
int ghar = 0;
int dukaan = 0;
int last;
int stop = 9999999;
bool check(int mid){
    int timer = 0;
    int prev;
    int food = mid;
    for(int i = 1 ; i <= last; ++i){
        ++timer;
        if(str[i] == 'H'){
            --food;
            if(food == -1){
                prev = i;
            }
        }
        if(str[i] == 'S'){
            ++food;
            if(food == 0){
                int temp = timer;
                timer += (i - prev) << 1;
                temp += stop - i;
                temp += stop - prev;
                if(temp <= t){
                    return 1;
                }
            }
        }
    }
    for(int i = last + 1 ; food < 0 && i <= n ; ++i){
        ++timer;
        if(str[i] == 'S'){
            ++food;
            if(food == 0){
                timer += i - prev;
                break;
            }
        }
    }
    return timer <= t;
}
int binary(){
    int l = max(0 , ghar - dukaan);
    int r = ghar;
    while(l != r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}
int main(){
    cin >> n >> t;
    cin >> str;
    str = " " + str;
    for(int i = 1 ; i <= n ; ++i){
        if(str[i] == 'H'){
            ++ghar;
            last = i;
        }
        if(str[i] == 'S'){
            ++dukaan;
        }
    }
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(str[i] == 'H'){
            ++cnt1;
        }
        if(str[i] == 'S'){
            ++cnt2;
        }
        if(cnt1 == ghar && cnt2 >= cnt1){
            stop = i;
            break;
        }
    }
    if(last > t){
        cout << -1;
    }
    else{
        cout << binary();
    }
}