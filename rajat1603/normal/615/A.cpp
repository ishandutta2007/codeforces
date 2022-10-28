#include "bits/stdc++.h"
using namespace std;
int n , m;
set < int > s;
int x , y;
int main(){
    cin >> n >> m;
    while(n--){
        cin >> x;
        while(x--){
            cin >> y;
            s.insert(y);
        }
    }
    if(s.size() == m){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}