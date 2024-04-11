#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int arr[N];
int cnt1[N];
int cnt2[N];
int idx1[N];
int idx2[N];
vector < pair < int , int > > ans;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        cnt1[i] = cnt1[i - 1] + (arr[i] == 1);
        cnt2[i] = cnt2[i - 1] + (arr[i] == 2);
    }
    for(int i = cnt1[n] + 1 ; i < N ; ++i){
        idx1[i] = n + 1;
    }
    for(int i = cnt2[n] + 1 ; i < N ; ++i){
        idx2[i] = n + 1;
    }
    for(int i = n ; i >= 1 ; --i){
        idx1[cnt1[i]] = i;
        idx2[cnt2[i]] = i;
    }
    for(int t = n ; t >= 1 ; --t){
        int awin = 0;
        int bwin = 0;
        int idx = 1;
        bool ok = 1;
        int last = -1;
        while(idx <= n){
            int idxa = idx1[t + cnt1[idx - 1]];
            int idxb = idx2[t + cnt2[idx - 1]];
            if(min(idxa , idxb) > n){
                ok = 0;
                break;
            }
            if(idxa < idxb){
                ++awin;
                idx = idxa + 1;
                last = 1;
            }
            else{
                ++bwin;
                idx = idxb + 1;
                last = 2;
            }
        }
        int s;
        if(ok){
            if(last == 1){
                s = awin;
                if(bwin >= s){
                    ok = 0;
                }
            }
            else{
                s = bwin;
                if(awin >= s){
                    ok = 0;
                }
            }
        }
        if(ok){
            ans.emplace_back(make_pair(s , t));
        }
    }
    sort(ans.begin() , ans.end());
    printf("%d\n" , int(ans.size()));
    for(auto it : ans){
        printf("%d %d\n" , it.first , it.second);
    }
}