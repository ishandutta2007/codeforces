#include "bits/stdc++.h"
using namespace std;
const int N = 104;
int n , m;
string arr[N];
int val[N][N] = {0};
bool ok = 1;
int steps = 0;
int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i){
        cin >> arr[i];
    }
    while(ok){
        ok = 0;
        int x = -1;
        int y = -1;
        int add = 0;
        for(int i = n - 1 ; i >= 0 ; --i){
            for(int j = m - 1 ; j >= 0 ; --j){
                if((arr[i][j] == 'W' && val[i][j] != 1 )|| (arr[i][j] == 'B' && val[i][j] != -1)){
                    ok = 1;
                    if(i + j > x + y){
                        x = i;
                        y = j;
                        if(arr[i][j] == 'W'){
                            add = 1 - val[i][j];
                        }
                        else{
                            add = -1 - val[i][j];
                        }
                    }
                }
            }
        }
        if(!ok){
            break;
        }
        for(int i = 0 ; i <= x ; ++i){
            for(int j = 0 ; j <= y ; ++j){
                val[i][j] += add;
            }
        }
        steps ++;
    }
    cout << steps;
}