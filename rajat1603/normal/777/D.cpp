#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
int n;
string arr[N];
char str[N];
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%s" , str);
        arr[i] = str;
    }
    for(int i = n - 1 ; i >= 1 ; --i){
        int x = arr[i].size();
        int y = arr[i + 1].size();
        int idx = -1;
        bool ok = 0;
        for(int j = 1 ; j <= min(x , y) ; ++j){
            if(arr[i][j] < arr[i + 1][j]){
                ok = 1;
                break;
            }
            if(arr[i][j] > arr[i + 1][j]){
                idx = j - 1;
                break;
            }
        }
        if(!ok){
            if(idx == -1){
                while(arr[i].size() > arr[i + 1].size()){
                    arr[i].pop_back();
                }
            }
            else{
                while(arr[i].size() - 1 > idx){
                    arr[i].pop_back();
                }
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        for(char c : arr[i]){
            putchar(c);
        }
        printf("\n");
    }
}