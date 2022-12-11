#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int main(){

    string a,b;
    cin >> a >> b;
    if(a==b){cout << -1; exit(0);}
    cout << max(a.size(),b.size());
    return 0;
}