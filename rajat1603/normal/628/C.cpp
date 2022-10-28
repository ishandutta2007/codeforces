#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , k;
char arr[N];
char ans[N];
int tot = 0;
int main(){
    scanf("%d %d" , &n , &k);
    scanf("%s" , arr);
    for(int i = 0 ; i < n ; ++i){
        tot += max('z' - arr[i] , arr[i] - 'a');
    }
    if(tot < k){
        printf("-1\n");
        return 0;
    }
    for(int i = 0 ; i < n ; ++i){
        ans[i] = arr[i];
    }
    for(int i = 0 ; i < n ; ++i){
        int tmp1 = 'z' - arr[i];
        int tmp2 = arr[i] - 'a';
        if(tmp1 >= tmp2){
            while(ans[i] < 'z' && k){
                ++ans[i];
                --k;
            }
        }
        else{
            while(ans[i] > 'a' && k){
                --ans[i];
                --k;
            }
        }
    }
    printf("%s" , ans);
}