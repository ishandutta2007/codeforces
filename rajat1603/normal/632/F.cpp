#include "bits/stdc++.h"
using namespace std;
const int N = 2505;
int n;
pair < int , pair < int , int > > arr[N * N];
long long row[N][1 + (N >> 6)];
int cur = 0;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            ++cur;
            scanf("%d" , &arr[cur].first);
            arr[cur].second = make_pair(i , j);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(arr[(i - 1) * n + i].first){
            printf("NOT MAGIC\n");
            return 0;
        }
        for(int j = 1 ; j <= n ; ++j){
            if(arr[(i - 1) * n + j].first != arr[(j - 1) * n + i].first){
                printf("NOT MAGIC\n");
                return 0;
            }
        }
    }
    sort(arr + 1 , arr + 1 + cur);
    arr[0].first = -1;
    for(int i = 1 ; i <= cur ; ++i){
        int x = arr[i].second.first;
        int y = arr[i].second.second;
        for(int j = (n >> 6) ; j >= 0 ; --j){
            if(row[x][j] & row[y][j]){
                printf("NOT MAGIC\n");
                return 0;
            }
        }
        if(arr[i].first != arr[i - 1].first){
            for(int j = i - 1 ; arr[j].first == arr[i - 1].first ; --j){
                x = arr[j].second.first;
                y = arr[j].second.second;
                row[x][y >> 6] |= 1LL << (y & 63);
            }
        }
    }
    printf("MAGIC\n");
}