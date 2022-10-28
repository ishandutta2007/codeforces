#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , a , cf , cm;
long long m;
pair < int , int > arr[N];
long long pre[N];
long long ans = -1;
long long idm;
int idx;
int mnval = 0;
int idxx;
bool check(int val , int pos){
    if(arr[n].first >= val){
        return 1;
    }
    int l = pos;
    int r = n;
    while(l < r){
        int mid = l + r >> 1;
        if(arr[mid].first >= val){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    if(m >= 1LL * val * (n - l + 1) - pre[n] + pre[r - 1]){
        return 1;
    }
    return 0;
}
long long solve(int idx){
    int l = 1;
    int r = a + 1;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid , idx)){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    mnval = l - 1;
    return 1LL * (l - 1LL) * cm;
}
int main(){
    scanf("%d %d %d %d %lld" , &n , &a , &cf , &cm , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &arr[i].first);
        arr[i].second = i;
    }
    sort(arr + 1 , arr + 1 + n);
    reverse(arr + 1 , arr + 1 + n);
    pre[0] = 0;
    for(int i = 1 ; i <= n ; ++i){
        pre[i] = pre[i - 1] + arr[i].first;
    }
    ans = solve(1);
    idx = 0;
    idm = m;
    idxx = mnval;
    for(int i = 1 ; i <= n ; ++i){
        m -= a - arr[i].first;
        if(m < 0){
            break;
        }
        long long tmp = i * cf + solve(i + 1);
        if(tmp > ans){
            ans = tmp;
            idx = i;
            idm = m;
            idxx = mnval;
        }
    }
    printf("%lld\n" , ans);
    for(int i = 1 ; i <= idx ; ++i){
        arr[i].first = a;
    }
    m = idm;
    for(int i = n ; i >= idx + 1 ; --i){
        if(arr[i].first < idxx){
            int tmp = idxx - arr[i].first;
            if(m >= tmp){
                m -= tmp;
                arr[i].first = idxx;
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        swap(arr[i].first , arr[i].second);
    }
    sort(arr + 1 , arr + 1 + n);
    for(int i = 1 ; i <= n ; ++i){
        printf("%d " , arr[i].second);
    }
}