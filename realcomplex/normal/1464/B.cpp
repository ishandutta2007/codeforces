#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
bool can[N];

int main(){
    fastIO;
    string s;
    cin >> s;
    ll x,y;
    cin >> x >> y;
    ll cur = 0;
    int n = s.size();
    int cnt0 = 0, cnt1 = 0;
    for(int i = 0 ; i < n; i ++ ){
        if(s[i] == '?') {
            can[i]=true;
            s[i]='0';
        }
        if(s[i] == '0'){
            cur += cnt1 * 1ll * y;
            cnt0++;
        }
        else{
            cur += cnt0 * 1ll * x;
            cnt1++;
        }
    }
    ll soln = cur;
    int pf0 = 0;
    int pf1 = 0;
    int sf0 = cnt0;
    int sf1 = cnt1;
    for(int i = 0 ; i < n; i ++ ){
        if(s[i] == '0') sf0 -- ;
        else sf1 -- ;
        if(can[i]){
            cur -= pf1 * 1ll * y;
            cur -= sf1 * 1ll * x;
            cur += pf0 * 1ll * x;
            cur += sf0 * 1ll * y;
            s[i] = '1';
        }
        soln = min(soln, cur);
        if(s[i] == '0'){
            pf0 ++ ;
        }
        else{
            pf1 ++ ;
        }
    }
    sf0 = pf0;
    sf1 = pf1;
    pf0 = 0;
    pf1 = 0;
    // 10 - y | 01 - x
    for(int i = 0 ; i < n; i ++ ){
        if(s[i]=='0')sf0--;
        else sf1--;
        if(can[i]){
            cur -= pf0 * 1ll * x;
            cur -= sf0 * 1ll * y;
            cur += pf1 * 1ll * y;
            cur += sf1 * 1ll * x;
            s[i]='0';
        }
        soln = min(soln, cur);
        if(s[i] == '0'){
            pf0 ++ ;
        }
        else{
            pf1 ++ ;
        }
    }
    cout << soln;
    return 0;
}