#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , m , k , s;
int a[N];
int b[N];
int type , cst;
pair < long long , int > arr1[N];
pair < long long , int > arr2[N];
int cnt1 = 0;
int cnt2 = 0;
bool check(int val){
    int md = 1e6 + 6;
    int mp = 1e6 + 6;
    for(int i = 1 ; i <= val ; ++i){
        if(a[i] < md){
            md = a[i];
        }
        if(b[i] < mp){
            mp = b[i];
        }
    }
    for(int i = 0 ; i <= k ; ++i){
        if(arr1[i].first == -1 || arr2[k - i].first == -1){
            continue;
        }
        long long cst1 = arr1[i].first * md;
        long long cst2 = arr2[k - i].first * mp;
        if(cst1 + cst2 <= s){
            return 1;
        }
    }
    return 0;
}
void retrieve(int val){
    int md = 1e6 + 6;
    int mp = 1e6 + 6;
    int idd = 0;
    int idp = 0;
    for(int i = 1 ; i <= val ; ++i){
        if(a[i] < md){
            md = a[i];
            idd = i;
        }
        if(b[i] < mp){
            mp = b[i];
            idp = i;
        }
    }
    for(int i = 0 ; i <= k ; ++i){
        if(arr1[i].first == -1 || arr2[k - i].first == -1){
            continue;
        }
        long long cst1 = arr1[i].first * md;
        long long cst2 = arr2[k - i].first * mp;
        if(cst1 + cst2 <= s){
            for(int j = 1 ; j <= i ; ++j){
                printf("%d %d\n" , arr1[j].second , idd);
            }
            for(int j = 1 ; j <= k - i ; ++j){
                printf("%d %d\n" , arr2[j].second , idp);
            }
            return;
        }
    }
}
int main(){
    scanf("%d %d %d %d" , &n , &m , &k , &s);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , a + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , b + i);
    }
    arr1[0] = make_pair(0 , 0);
    arr2[0] = make_pair(0 , 0);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , &type , &cst);
        if(type & 1){
            arr1[++cnt1] = make_pair(cst , i);
        }
        else{
            arr2[++cnt2] = make_pair(cst , i);
        }
    }
    sort(arr1 + 1 , arr1 + 1 + cnt1);
    sort(arr2 + 1 , arr2 + 1 + cnt2);
    for(int i = 2 ; i <= cnt1 ; ++i){
        arr1[i].first += arr1[i - 1].first;
    }
    for(int i = 2 ; i <= cnt2 ; ++i){
        arr2[i].first += arr2[i - 1].first;
    }
    while(cnt1 <= k){
        arr1[++cnt1] = make_pair(-1 , m + 1);
    }
    while(cnt2 <= k){
        arr2[++cnt2] = make_pair(-1 , m + 1);
    }
    if(!check(n)){
        printf("-1\n");
        return 0;
    }
    int l = 1;
    int r = n;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    printf("%d\n" , l);
    retrieve(l);
}