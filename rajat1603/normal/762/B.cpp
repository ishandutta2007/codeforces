#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int a , b , c;
int n;
int val;
char str[10];
pair < int , char > arr[N];
int ans1;
long long ans2;
int main(){
    scanf("%d %d %d" , &a , &b , &c);
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d%s" , &val , str);
        arr[i] = make_pair(val , str[0]);
    }
    sort(arr + 1 , arr + 1 + n);
    ans1 = 0;
    ans2 = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(arr[i].second == 'U'){
            if(a){
                --a;
                ++ans1;
                ans2 += arr[i].first;
            }
            else if(c){
                --c;
                ++ans1;
                ans2 += arr[i].first;
            }
        }
        else{
            if(b){
                --b;
                ++ans1;
                ans2 += arr[i].first;
            }
            else if(c){
                --c;
                ++ans1;
                ans2 += arr[i].first;
            }
        }
    }
    printf("%d %lld\n" , ans1 , ans2);
}