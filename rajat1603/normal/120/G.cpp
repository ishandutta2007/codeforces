#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n , t;
int a[N][3];
int b[N][3];
int m;
string word[N];
int c[N];
queue < int > cards;
int d[N][N] = {0};
int cur1 = 1;
int cur2 = 1;
int k , q;
int timer;
vector < int > ans[N];
int main(){
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    cin >> n >> t;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= 2 ; ++j){
            cin >> a[i][j] >> b[i][j];
        }
    }
    timer = t;
    cin >> m;
    for(int i = 1 ; i <= m ; ++i){
        cin >> word[i];
        cin >> c[i];
        cards.push(i);
    }
    while(!cards.empty()){
        k = cards.front();
        cards.pop();
        q = cur2 ^ 3;
        int temp = max(1 , c[k] - (a[cur1][cur2] + b[cur1][q]) - d[cur1][k]);
        if(temp <= timer){
            ans[cur1].emplace_back(k);
        }
        else{
            d[cur1][k] += timer;
            cards.push(k);
        }
        timer -= temp;
        if(timer <= 0){
            timer = t;
            cur1 += 1;
            if(cur1 > n){
                cur1 = 1;
                cur2 ^= 3;
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        cout << ans[i].size();
        for(int x : ans[i]){
            cout << " " << word[x];
        }
        cout << endl;
    }
}