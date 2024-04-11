#include "bits/stdc++.h"
using namespace std;
vector < pair < long long , long long > > arr;
int h;
int q;
int hi;
long long l , r;
bool ans;
long long start;
long long finish;
long long answer = -1;
int cnt = 0;
int main(){
    cin >> h >> q;
    start = 1LL << (h - 1);
    finish = (1LL << h) - 1;
    arr.emplace_back(make_pair(start - 1 , start - 1));
    for(int i = 1 ; i <= q ; ++i){
        cin >> hi >> l >> r >> ans;
        for(int i = hi + 1 ; i <= h ; ++i){
            l += l;
            r += r;
            r |= 1;
        }
        if(ans){
            if(l != start){
                arr.emplace_back(make_pair(start , l - 1));
            }
            if(r != finish){
                arr.emplace_back(r + 1 , finish);
            }
        }
        else{
            arr.emplace_back(make_pair(l , r));
        }
    }
    arr.emplace_back(make_pair(finish + 1 , finish + 1));
    sort(arr.begin() , arr.end());
    auto it = arr.begin();
    long long mx = start - 1;
    while(it != arr.end()){
        while(it != arr.end() && it -> first <= mx){
            mx = max(mx , it -> second);
            ++it;
        }
        if(it != arr.end()){
            if(it -> first - mx - 1 > 1){
                cout << "Data not sufficient!\n";
                return 0;
            }
            else if((it -> first - mx - 1) == 1){
                answer = mx + 1;
                ++cnt;
                mx = max(mx , it -> second);
                ++it;
            }
            else{
                mx = max(mx , it -> second);
            }
            if(cnt > 1){
                cout << "Data not sufficient!\n";
                return 0;
            }
        }
    }
    if(answer == -1){
        cout << "Game cheated!";
    }
    else{
        cout << answer;
    }
}