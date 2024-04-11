#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main()
{
    int n,m;
    cin >> n >> m;
    int l = 0;
    while(n>0 && m>0){
        n--;
        m--;
        l = (l+1)%2;
    }
    if(l == 1){
        cout << "Akshat";
    }
    else{
        cout << "Malvika";
    }
    return 0;
}