#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pair<int,int> pii
#define abs(a) ((a<0) ? -a : a)
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);

#define TEST int q;cin>>q;while(q--)Solution()

/*******************************/

void Solution(){
    ll n;
    cin >> n;
    if(n%4==0)
    cout << n*4+1 << "\n";
    else if(n%4==1)
    cout << n*2+1 << "\n";
    else if(n%4==2)
    cout << n*4+1 << "\n";
    else
    cout << n+1 << "\n";

}

/*******************************/

int main(){
    fastIO;
    TEST;
    //Solution();
    return 0;
}