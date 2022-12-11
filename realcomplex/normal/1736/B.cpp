#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int lcm(int a, int b){
    return (a * b) / __gcd(a, b);
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        vector<int> b(n + 1);
        vector<int> a(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> a[i];
            if(b[i] == 0) b[i] = a[i];
            else b[i] = lcm(b[i], a[i]);
            if(b[i + 1] == 0) b[i + 1] = a[i];
            else b[i + 1] = lcm(b[i + 1], a[i]);
        }
        bool soln = true;
        for(int i = 0 ; i < n; i ++ ){
            if(a[i] != __gcd(b[i], b[i + 1])){
                soln=false;
                break;
            }
        }
        if(soln){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}