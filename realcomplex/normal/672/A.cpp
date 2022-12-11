#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int inc = 10;
    int l = 1;
    int sum = 0;
    int p = 1;
    while(sum<n){
        if(inc == p){
            l++;
            inc*=10;
        }
        sum += l;
        p++;
    }
    p--;
    while(sum>n){
        p/=10;
        sum--;
    }
    cout << p%10;
    return 0;
}