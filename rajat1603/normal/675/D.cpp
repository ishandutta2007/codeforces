#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
set < pair < int , int > > s;
long long tot = 0;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    s.insert(make_pair(arr[1] , 0));
    for(int i = 2 ; i <= n ; ++i){
        auto it = s.lower_bound(make_pair(arr[i] , -1));
        if(it == s.end()){
            --it;
            tot += it -> second + 1;
            printf("%d " , it -> first);
            s.insert(make_pair(arr[i] , it -> second + 1));
        }
        else{
            if(it != s.begin()){
                auto it2 = prev(it);
                if(it2 -> second < it -> second){
                    tot += it -> second + 1;
                    s.insert(make_pair(arr[i] , it -> second + 1));
                    printf("%d " , it -> first);  
                }
                else{
                    tot += it2 -> second + 1;
                    s.insert(make_pair(arr[i] , it2 -> second + 1));
                    printf("%d " , it2 -> first);
                }
            }
            else{
                tot += it -> second + 1;
                s.insert(make_pair(arr[i] , it -> second + 1));       
                printf("%d " , it -> first);
            }
        }
    }
}