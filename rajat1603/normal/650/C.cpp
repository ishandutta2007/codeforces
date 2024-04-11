#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n , m;
vector < pair < int , int > > rows[N];
vector < pair < int , int > > cols[N];
vector < int > v[N];
int rmax[N];
int cmax[N];
int val;
int ans[N];
pair < int , int > arr[N];
int visited[N];
int mx;
inline int get(int i , int j){
    return (i - 1) * m + j;
}
void dfs(int node , int val){
    int r = 1 + ((node - 1) / m);
    int c = 1 + ((node - 1) % m);
    mx = max(mx , max(rmax[r] , cmax[c]));
    rmax[r] = max(rmax[r] , mx * val);
    cmax[c] = max(cmax[c] , mx * val);
    ans[node] = mx;
    for(int next : v[node]){
        if(visited[next] == val){
            visited[next] = val + 1;
            dfs(next , val);
        }
    }
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        rows[i].resize(m);
    }
    for(int i = 1 ; i <= m ; ++i){
        cols[i].resize(n);
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            scanf("%d" , &val);
            arr[get(i , j)] = make_pair(val , get(i , j)); 
            rows[i][j - 1] = make_pair(val , j);
            cols[j][i - 1] = make_pair(val , i);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        sort(rows[i].begin() , rows[i].end());
        for(int j = 1 ; j < m ; ++j){
            if(rows[i][j].first == rows[i][j - 1].first){
                v[get(i , rows[i][j].second)].emplace_back(get(i , rows[i][j - 1].second));
                v[get(i , rows[i][j - 1].second)].emplace_back(get(i , rows[i][j].second));
            }
        }
    }
    for(int j = 1 ; j <= m ; ++j){
        sort(cols[j].begin() , cols[j].end());
        for(int i = 1 ; i < n ; ++i){
            if(cols[j][i].first == cols[j][i - 1].first){
                v[get(cols[j][i].second , j)].emplace_back(get(cols[j][i - 1].second , j));
                v[get(cols[j][i - 1].second , j)].emplace_back(get(cols[j][i].second , j));
            }
        }
    }
    sort(arr + 1 , arr + 1 + n * m);
    for(int i = 1 ; i <= n * m ; ++i){
        if(!visited[arr[i].second]){
            mx = 0;
            dfs(arr[i].second , 0);
            ++mx;
            dfs(arr[i].second , 1);
        }
    }
    for(int i = 1 ; i <= n * m ; ++i){
        printf("%d " , ans[i]);
        if(i % m == 0){
            printf("\n");
        }
    }
}