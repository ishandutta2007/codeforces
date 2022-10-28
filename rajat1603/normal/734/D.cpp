#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
int n;
char c[N];
int x[N];
int y[N];
vector < pair < int , char > > tmp;
char temp[3];
void solve(char who){
    sort(tmp.begin() , tmp.end());
    for(int i = 0 ; i < 2 ; ++i){
        char last = '$';
        for(auto it : tmp){
            if(it.second == 'K'){
                if(last == 'Q' || last == who){
                    printf("YES\n");
                    exit(0);
                }
            }
            last = it.second;
        }
        reverse(tmp.begin() , tmp.end());
    }
    tmp.clear();
}
int main(){
    scanf("%d" , &n);
    scanf("%d %d" , x , y);
    c[0] = 'K';
    for(int i = 1 ; i <= n ; ++i){
        scanf("%s %d %d" , temp , x + i , y + i);
        c[i] = temp[0];
    }
    tmp.clear();
    for(int i = 0 ; i <= n ; ++i){
        if(x[i] == x[0]){
            tmp.push_back({y[i] , c[i]});
        }
    }
    solve('R');
    for(int i = 0 ; i <= n ; ++i){
        if(y[i] == y[0]){
            tmp.push_back({x[i] , c[i]});
        }
    }
    solve('R');
    for(int i = 0 ; i <= n ; ++i){
        if(x[i] + y[i] == x[0] + y[0]){
            tmp.push_back({x[i] , c[i]});
        }
    }
    solve('B');
    for(int i = 0 ; i <= n ; ++i){
        if(x[i] - y[i] == x[0] - y[0]){
            tmp.push_back({x[i] , c[i]});
        }
    }
    solve('B');
    printf("NO\n");
}