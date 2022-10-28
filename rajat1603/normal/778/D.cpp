#include "bits/stdc++.h"
using namespace std;
const int N = 55;
int n , m;
vector < string > a , b;
void solve(int x , int y , int dir , vector < string > &v , vector < pair < int , int > > &ans){
    if(dir){
        if(v[x][y] != 'L'){
            solve(x , y + 1 , 0 , v , ans);
            ans.emplace_back(make_pair(x , y));
            v[x][y] = 'L';
            v[x][y + 1] = 'R';
            v[x + 1][y] = 'L';
            v[x + 1][y + 1] = 'R';
        }
    }
    else{
        if(v[x][y] != 'U'){
            solve(x + 1 , y , 1 , v , ans);
            ans.emplace_back(make_pair(x , y));
            v[x][y] = 'U';
            v[x + 1][y] = 'D';
            v[x][y + 1] = 'U';
            v[x + 1][y + 1] = 'D';
        }
    }
}
vector < pair < int , int > > solve(vector < string > &v){
    vector < pair < int , int > > ans;
    ans.clear();
    if(m & 1){
        for(int i = 1 ; i <= n ; i += 2){
            for(int j = 1 ; j <= m ; ++j){
                solve(i , j , 0 , v , ans);
            }
        }
    }
    else{
        for(int i = 1 ; i <= n ; ++i){
            for(int j = 1 ; j <= m ; j += 2){
                solve(i , j , 1 , v , ans);
            }
        }
    }
    return ans;
}
int main(){
    cin >> n >> m;
    a.resize(n + 1);
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
        a[i] = " " + a[i];
    }
    b.resize(n + 1);
    for(int i = 1 ; i <= n ; ++i){
        cin >> b[i];
        b[i] = " " + b[i];
    }
    auto x = solve(a);
    auto y = solve(b);
    printf("%d\n" , int(x.size() + y.size()));
    for(auto it : x){
        printf("%d %d\n" , it.first , it.second);
    }
    reverse(y.begin() , y.end());
    for(auto it : y){
        printf("%d %d\n" , it.first , it.second);
    }
}