#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int main(){

    int a,b;
    cin >> a >> b;
    int am = 0;
    int ot = 0;
    while(a>0 || ot >= b){
        am+=a;
        ot += a;
        a = 0;
        a = ot/b;
        ot %= b;
    }
    cout << am;
    return 0;
}