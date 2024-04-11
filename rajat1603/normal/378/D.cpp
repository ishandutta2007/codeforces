#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m , s;
pair < int , int > a[N];
pair < pair < int , int > , int > b[N];
priority_queue < pair < int , int > > pq;
int ans[N];
bool solve(int day){
    while(!pq.empty()){
        pq.pop();
    }
    int idx = n;
    int lft = s;
    for(int i = m ; i >= 1 ; i -= day){
        while(idx >= 1 && b[idx].first.first >= a[i].first){
            pq.push(make_pair(-b[idx].first.second , b[idx].second));
            idx--;
        }
        if(pq.empty()){
            return 0;
        }
        auto it = pq.top();
        pq.pop();
        lft += it.first;
        if(lft < 0){
            return 0;
        }
        for(int j = max(1 , i - day + 1) ; j <= i ; ++j){
            ans[a[j].second] = it.second;
        }
    }
    return 1;
}
int main(){
    scanf("%d %d %d" , &n , &m , &s);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d" , &a[i].first);
        a[i].second = i;
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &b[i].first.first);
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &b[i].first.second);
        b[i].second = i;
    }
    sort(a + 1 , a + 1 + m);
    sort(b + 1 , b + 1 + n);
    int l = 1;
    int r = m;
    while(l < r){
        int mid = l + r >> 1;
        if(solve(mid)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    if(solve(l)){
        printf("YES\n");
        for(int i = 1 ; i <= m ; ++i){
            printf("%d%c" , ans[i] , " \n"[i == m]);
        }
    }
    else{
        printf("NO\n");
    }
}