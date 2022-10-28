#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const int mod = 1e9 + 7;
inline int add(int a , int b){
    return (a + b) % mod;
}
int n , q;
string a[N];
string b[N];
vector < char > v[26][26];
int ans = 0;
int solve(set < int > tmp , int last , int left){
    int ans = 0;
    int mask3 = 0;
    set < int > nset;
    for(int i : tmp){
        for(int j = 1 ; j <= q ; ++j){
            if(a[j][0] - 'a' == i && a[j][1] - 'a' == last){
                nset.insert(b[j][0] - 'a');
            }
        }
    }
    if(left == 1){
        if(nset.find(0) != nset.end()){
            return 1;
        }
        return 0;
    }
    for(int i = 0 ; i < 6 ; ++i){
        ans = add(ans , solve(nset , i , left -1));
    }
    return ans;
}
int main(){
    cin >> n >> q;
    for(int i = 1 ; i <= q ; i++){
        cin >> a[i] >> b[i];
    }
    for(int i = 0 ; i < 6 ; ++i){
        set < int > tmp;
        tmp.insert(i);
        for(char j = 0 ; j < 6 ; ++j){
            ans = add(ans , solve(tmp , j , n - 1));
        }
    }
    cout << ans;
}