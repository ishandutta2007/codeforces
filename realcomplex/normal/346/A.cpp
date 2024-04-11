#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

void open(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}

int main()
{
    //open();
    int n;
    cin >> n;
    int moves = INT_MIN;
    int a[n+1];
    for(int j = 1;j<=n;j++){
        cin >> a[j];
        moves = max(moves,a[j]);
    }
    int gcd = a[1];
    for(int j = 2;j<=n;j++){
        gcd = __gcd(a[j],gcd);
    }
    moves/=gcd;
    moves-=n;
    if(moves&1){
        cout << "Alice";
    }
    else{
        cout << "Bob";
    }
    return 0;
}