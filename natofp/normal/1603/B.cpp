#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

void haha(){
    ll x, y; cin >> x >> y;
    if(x > y){
        cout << x * x + y << "\n";
        return;
    }
    if(x == y){
        cout << x << "\n";
        return;
    }
    ll debil = y / x * x;
    cout << debil + (y - debil) / 2 << "\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x; cin >> x;
    while(x--) haha();


    return 0;
}