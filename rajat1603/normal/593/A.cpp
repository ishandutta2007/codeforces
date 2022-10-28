#include "bits/stdc++.h"
using namespace std;
const int N = 101;
int n;
string str;
int mask[N];
int sz[N];
int ans = 0;
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        mask[i] = 0;
        cin >> str;
        for(char c : str){
            mask[i] |= 1 << (c - 'a');
        }
        sz[i] = str.size();
    }
    for(int i = 0 ; i < 26 ; ++i){
        for(int j = 0 ; j < 26 ; ++j){
            int curmask = (1 << i) | (1 << j);
            int len = 0;
            for(int k = 1 ; k <= n ; ++k){
                if((mask[k] | curmask) == curmask){
                    len += sz[k];
                }
            }
            ans = max(ans , len);
        }
    }
    cout << ans;
}