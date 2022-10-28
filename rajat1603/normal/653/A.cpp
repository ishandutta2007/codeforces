#include "bits/stdc++.h"
using namespace std;
const int N = 55;
const int MAX = 1e3 + 3;
int n;
int inp;
bool mark[MAX];
int main(){
    cin >> n;
    memset(mark , 0 , sizeof(mark));
    while(n--){
        cin >> inp;
        mark[inp] = 1;
    }
    for(int i = 1 ; i <= 1000 ;  ++i){
        int x = mark[i];
        x += mark[i - 1];
        x += mark[i + 1];
        if(x == 3){
            printf("YES\n");
            return 0;
        }
    }
    cout << "NO\n";
}