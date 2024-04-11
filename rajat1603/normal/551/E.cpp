#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
const int SQN = 750;
set < pair < int , int > > s1[SQN];
set < pair < int , int > > s2[SQN];
int lazy[SQN] = {0};
int start[SQN];
int finish[SQN];
int block[N];
int cur = 0;
int arr[N];
int n , q;
int l , r , x , type;
int y;
bool bann[SQN] = {0};
bool ban[N] = {0};
int main(){
    scanf("%d %d" , &n , &q);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    for(int i = 1 ; i <= n ;){
        start[++cur] = i;
        int j;
        for(j = i ; j <= i + SQN && j <= n ; ++j){
            s1[cur].insert(make_pair(arr[j] , j));
            s2[cur].insert(make_pair(arr[j] , -j));
            block[j] = cur;
            finish[cur] = j;
        }
        i = j;
    }
    while(q--){
        scanf("%d" , &type);
        if(type & 1){
            scanf("%d %d %d" , &l , &r , &x);
            for(int i = block[l] ; i <= block[r] ; ++i){
                if(start[i] >= l && finish[i] <= r){
                    if(!bann[i]){
                        lazy[i] += x;
                        if(lazy[i] > 1000000000){
                            bann[i] = 1;
                        }
                    }
                }
                else{
                    for(int j = max(l , start[i]) ; j <= min(finish[i] , r) ; ++j){
                        if(!ban[j]){
                            s1[i].erase(make_pair(arr[j] , j));
                            s2[i].erase(make_pair(arr[j] , -j));
                            arr[j]+= x;
                            if(arr[j] > 1000000000){
                                ban[j] = 1;
                                continue;
                            }
                            s1[i].insert(make_pair(arr[j] , j));
                            s2[i].insert(make_pair(arr[j] , -j));
                        }
                    }
                }
            }
        }
        else{
            scanf("%d" , &y);
            int leftmost = 0;
            int rightmost = -1;
            for(int i = 1 ; i <= cur ; ++i){
                if(bann[i]){
                    continue;
                }
                auto it = s1[i].lower_bound(make_pair(y - lazy[i] , 0));
                if(it != s1[i].end() && it -> first == y - lazy[i]){
                    leftmost = it -> second;
                    break;
                }
            }
            for(int i = cur ; i >= 1 ; --i){
                if(bann[i]){
                    continue;
                }
                auto it = s2[i].lower_bound(make_pair(y - lazy[i] , -n));
                if(it != s2[i].end() && it -> first == y - lazy[i]){
                    rightmost = -it -> second;
                    break;
                }
            }
            printf("%d\n" , rightmost - leftmost);
        }
    }
}