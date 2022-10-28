#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
pair < int , pair < int , int > > arr[N];
pair < int , pair < int , int > > ans[N];
int arr1[N];
int arr2[N];
int cur1 = 0;
int cur2 = 0;
int m , n;
pair < int , pair < int , int > > edges[N];
int parent[N];
int find(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}
bool join(int a , int b){
    if(find(a) == find(b)){
        return 0;
    }
    parent[find(a)] = find(b);
    return 1;
}
int cur = 1;
int curr1 = 1;
int curr2 = 3;
void rekt(){
    puts("-1");
    exit(0);
}
vector < pair < int , int > > v;
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , &arr[i].first , &arr[i].second.first);
        arr[i].second.second = i;
        if(arr[i].second.first){
            arr1[++cur1] = arr[i].first;
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        parent[i] = i;
    }
    sort(arr + 1 , arr + 1 + m);
    for(int i = 1 ; i <= m ; ++i){
        if(arr[i].second.first == 1){
            ans[arr[i].second.second] = make_pair(arr[i].first , make_pair(cur , cur + 1));
            ++cur;
        }
        else{
            v.emplace_back(make_pair(arr[i].second.second , arr[i].first));
        }
    }
    int cnt = 0;
    for(int i = 3 ; i <= n ; ++i){
        for(int j = 1 ; j < i - 1 ; ++j){
            if(cnt == v.size()){
                i = n + 1;
                break;
            }
            ++cnt;
            ans[v[cnt - 1].first] = make_pair(v[cnt - 1].second , make_pair(i , j));
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        edges[i] = ans[i];
    }
    sort(edges + 1 , edges + 1 + m);
    for(int i = 1 ; i <= m ; ++i){
        if(join(edges[i].second.first , edges[i].second.second)){
            arr2[++cur2] = edges[i].first;
        }
    }
    sort(arr1 + 1 , arr1 + 1 + cur1);
    sort(arr2 + 1 , arr2 + 1 + cur2);
    if(cur1 != cur2){
        rekt();
    }
    for(int i = 1 ; i <= cur1 ; ++i){
        if(arr1[i] != arr2[i]){
            rekt();
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        printf("%d %d\n" , ans[i].second.first , ans[i].second.second);
    }
}