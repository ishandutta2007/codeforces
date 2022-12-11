#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

void NO(){
    cout << ":(";
    exit(0);
}

string constr(string v){
    int co = 0, cl = 0;
    for(int i = 0 ; i < v.size(); i ++ ){
        if(v[i] == '(')
            co ++ ;
        else if(v[i] == ')')
            cl ++ ;
    }
    int m = v.size();
    if(co > m/2 || cl > m/2)
        NO();
    co = m/2 - co;
    for(int i = 0 ; i < v.size(); i ++ ){
        if(v[i] == '?' && co > 0){
            v[i] = '(';
            co -- ;
        }
    }
    for(int i = 0 ; i < v.size(); i ++ ){
        if(v[i] == '?')
            v[i] = ')';
    }
    int cnt = 0;
    for(int i = 0 ; i < v.size(); i ++ ){
        if(v[i] == '(')
            cnt ++ ;
        else
            cnt -- ;
        if(cnt < 0){
            NO();
        }
    }
    if(cnt != 0)
        NO();
    return v;
}

int main(){
    fastIO;
    int n;
    cin >> n;
    string t;
    cin >> t;
    if(n % 2 == 1) NO();
    if(n == 2){
        if(t[0] == ')' || t[1] == '('){
            NO();
        }
        cout << "()";
        exit(0);
    }
    if(t[0] == ')' || t[n-1] == '(')
        NO();
    string chk;
    for(int i = 1 ; i + 1 < n ; i ++ ){
        chk.push_back(t[i]);
    }
    chk = constr(chk);
    cout << "(" << chk << ")";
    return 0;
}