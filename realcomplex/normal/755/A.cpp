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
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    if(n==1)cout << 8;
    else if(n == 2)cout << 4;
    else cout << n-2;
    return 0;
}