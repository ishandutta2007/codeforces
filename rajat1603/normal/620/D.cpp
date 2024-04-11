#include "bits/stdc++.h"
using namespace std;
const int N = 2005;
int n;
int a[N];
int m;
int b[N];
long long ans;
int cnt1;
int a1 , a2;
int b1 , b2;
long long sum1 = 0 , sum2 = 0;
pair < long long , pair < int , int > > arr[N * N];
int cnt = 0;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , a + i);
        sum1 += a[i];
    }
    scanf("%d" , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d" , b + i);
        sum2 += b[i];
    }
    ans = abs(sum1 - sum2);
    cnt1 = 0;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            long long sum11 = sum1 - a[i] + b[j];
            long long sum22 = sum2 - b[j] + a[i];
            if(abs(sum11 - sum22) < ans){
                ans = abs(sum11 - sum22);
                cnt1 = 1;
                a1 = i;
                a2 = j;
            }
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        for(int j = i + 1 ; j <= m ; ++j){
            arr[++cnt] = make_pair(b[i] + b[j] , make_pair(i , j));
        }
    }
    arr[cnt + 1] = make_pair(1LL << 60 , make_pair(-1 , -1));
    arr[0] = make_pair(1LL << 60 , make_pair(-1 , -1));
    sort(arr + 1 , arr + 1 + cnt);
    for(int i = 1 ; i <= n ; ++i){
        for(int j = i + 1 ; j <= n ; ++j){
            long long tmpsum = sum1 - a[i] - a[j] - sum2 - a[i] - a[j];
            auto it = lower_bound(arr + 1 , arr + 1 + cnt + 1 , make_pair(-(tmpsum / 2LL) , make_pair(-1 , -1)));
            if(it -> first != (1LL << 60)){
                long long s1 = sum1 - a[i] - a[j] + it -> first;
                long long s2 = sum2 - it -> first + a[i] + a[j];
                if(abs(s1 - s2) < ans){
                    ans = abs(s1 - s2);
                    cnt1 = 2;
                    a1 = i;
                    b1 = j;
                    a2 = it -> second.first;
                    b2 = it -> second.second;
                }
            }
            --it;
            if(it -> first != (1LL << 60)){
                long long s1 = sum1 - a[i] - a[j] + it -> first;
                long long s2 = sum2 - it -> first + a[i] + a[j];
                if(abs(s1 - s2) < ans){
                    ans = abs(s1 - s2);
                    cnt1 = 2;
                    a1 = i;
                    b1 = j;
                    a2 = it -> second.first;
                    b2 = it -> second.second;
                }
            }
            //sum1 - arr[i] - arr[j]  = sum2 - 2x + arr[i] + arr[j]
            //sum1 - arr[i] - arr[j] - sum2 - arr[i] - arr[j] = -2x 
        }
    }
    printf("%lld\n" , ans);
    printf("%d\n" , cnt1);
    if(cnt1){
        printf("%d %d\n" , a1 , a2);
    }
    if(cnt1 > 1){
        printf("%d %d\n" , b1 , b2);
    }
}