#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

int main(){
    ll x,y;
    cin >> y >> x;
    if(x==0){
        cout << "No";
        return 0;
    }
    if(x==1){
        if(y==0){
            cout << "Yes\n";
            return 0;
        }
        else{
            cout << "No\n";
            return 0;
        }
    }
    ll req = x-1;
    if(y<req or (y-req) % 2 ==1){
        cout << "No";
        return 0;
    }
    cout << "Yes";
    return 0;
}