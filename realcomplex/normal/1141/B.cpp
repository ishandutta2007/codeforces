#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int n;
    cin >> n;
    int a[n];
    int cur = 0;
    int answ = 0;
    int pref = 0, suf = 0;
    int ok = 1;
    for(int i = 0 ; i < n; i ++ ){
        cin >> a[i];
        if(a[i] == 1){
            if(ok) pref ++ ;
            cur ++ ;
        }
        else{
            ok = 0;
            cur = 0;
        }
        answ = max(answ, cur);
    }
    suf = cur;
    answ = max(answ, pref + suf);
    cout << answ;
    return 0;
}