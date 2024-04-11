#include "bits/stdc++.h"
using namespace std;
const int N = 5005;
const int MAX = 370;
int n;
char t;
int a , b;
int m1[MAX];
int m2[MAX];
int ans = 0;
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> t >> a >> b;
        if(t == 'M'){
            ++m1[a];
            --m1[b + 1];
        }
        else{
            ++m2[a];
            --m2[b + 1];
        }
    }
    for(int i = 1 ; i < MAX ; ++i){
        m1[i] += m1[i - 1];
        m2[i] += m2[i - 1];
        ans = max(ans , min(m1[i] , m2[i]));
    }
    cout << ans + ans;
}