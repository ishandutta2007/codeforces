#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

int main(){
    fastIO;
    int n;
    cin >> n;
    if(n>=37){
        cout << -1 << "\n";
    }
    else{
        while(n>1){
            cout << 8;
            n-=2;
        }
        if(n!=0){
            cout << 4;
        }
    }
    return 0;
}