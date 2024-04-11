#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second
#define t abs

int main(){

    int a,b,c;
    cin >> a >> b >> c;
    int w1,w2;
    w1 = b/a;
    w2 = c/a;
    int a1,a2;
    a1 = b%a;
    a2 = c%a;
    if((a1!=0 && w2 == 0) || (a2!=0 && w1 == 0)){
        cout << -1;
    }
    else{
        cout << (b/a) + (c/a);
    }
    return 0;
}