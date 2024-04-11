
#include "bits/stdc++.h"
using namespace std;
const int N = 55;
int n , m;
char str[N][N];
int ans;
int min(int a , int b , int c){
    return min(min(a , b) , c);
}
int getdig(int row){
    int res = N;
    for(int i = 0 ; i < m ; ++i){
        if(isdigit(str[row][i])){
            res = min(res , i , m - i);
        }
    }
    return res;
}
int getalpha(int row){
    int res = N;
    for(int i = 0 ; i < m ; ++i){
        if(isalpha(str[row][i])){
            res = min(res , i , m - i);
        }
    }
    return res;
}
bool isspecial(char c){
    return (c == '#') || (c == '*') || (c == '&');
}
int getspecial(int row){
    int res = N;
    for(int i = 0 ; i < m ; ++i){
        if(isspecial(str[row][i])){
            res = min(res , i , m - i);
        }
    }
    return res;
}
int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i){
        cin >> str[i];
    }
    ans = N * N * N;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            for(int k = 0 ; k < n ; ++k){
                if(i != j && j != k && i != k){
                    ans = min(ans , getdig(i) + getalpha(j) + getspecial(k));
                }
            }
        }
    }
    cout << ans << endl;
}