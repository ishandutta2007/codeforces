#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);cin.tie(false);
    int a,b,c,d,e,f,n;
    cin >> a >> b >> c >> d >> e >> f >> n;
    a = a+b+c;
    d = d+e+f;
    int need = a/5;
    int need2 = d/10;
    if(a%5!=0){
        need++;
    }
    if(d%10!=0){
        need2++;
    }
    if(need2+need <= n){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}