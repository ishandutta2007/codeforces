#include "bits/stdc++.h"
using namespace std;
const int N = 1e2 + 2;
const int inf = 1e3 + 3;
int n;
int a[N] , d[N];
int tmp[N];
pair < int , int > arr[N];
pair < int , int > fff[N];
int solve(){
    for(int i = 1 ; i <= n ; ++i){
        fff[i] = make_pair(i - a[i] * inf , i);
    }
    sort(fff + 1 , fff + 1 + n);
    for(int i = 1 ; i <= n ; ++i){
        arr[i] = {fff[i].second , fff[i].first};
    }
    int res = 0;
    for(int i = 1 ; i <= n ; ++i){
        int idx = tmp[i];
        int where;
        for(int j = 1 ; j <= n ; ++j){
            if(arr[j].first == idx){
                where = j;
                break;
            }
        }
        arr[where].second = idx - (a[idx] + d[idx]) * inf;
        while(where > 1 && arr[where - 1].second > arr[where].second){
            swap(arr[where] , arr[where - 1]);
            --where;
            ++res;
        }
        while(where < n && arr[where + 1].second < arr[where].second){
            swap(arr[where] , arr[where + 1]);
            ++where;
            ++res;
        }
    }
    return res;
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , a + i , d + i);
        tmp[i] = i;
    }
    sort(tmp + 1 , tmp + 1 + n , [](int x , int y){
        if(d[x] > 0 && d[y] > 0){
            return make_pair(a[x] , -x) < make_pair(a[y] , -y);
        }
        if(d[x] < 0 && d[y] < 0){
            return make_pair(a[x] , -x) > make_pair(a[y] , -y);
        }
        return d[x] < d[y];
    });
    printf("%d\n" , solve());
}