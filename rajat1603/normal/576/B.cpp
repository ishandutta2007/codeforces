#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
bool visited[N];
vector < int > v[N];
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        visited[i] = 0;
    }
    for(int i = 1 ; i <= n ; ++i){
        if(arr[i] == i){
            puts("YES");
            for(int j = 1 ; j <= n ; ++j){
                if(i != j){
                    printf("%d %d\n" , j , i);
                }
            }
            return 0;
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(!visited[i]){
            int cur = i;
            do{
                visited[cur] = 1;
                v[i].emplace_back(cur);
                cur = arr[cur];
            }while(cur != i);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(v[i].size() & 1){
            puts("NO");
            return 0;
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(v[i].size() == 2){
            puts("YES");
            printf("%d %d\n" , v[i][0] , v[i][1]);
            for(int j = 1 ; j <= n ; ++j){
                if(j != i){
                    for(int k = 0 ; k < v[j].size() ; ++k){
                        printf("%d %d\n" , v[j][k] , v[i][k & 1]);
                    }
                }
            }
            return 0;
        }
    }
    puts("NO");
}