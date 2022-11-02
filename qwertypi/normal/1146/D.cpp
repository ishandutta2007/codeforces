#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int curMax = 0;
ll ans = 0;
int cnt = 1;
int gcd(int a, int b){
    if(a < b){
        swap(a, b);
    }
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    int _gcd = gcd(a, b);
    a /= _gcd;
    b /= _gcd;
    int pos = 0;
    do{
        if(pos >= b){
            cnt += pos / b;
            pos %= b;
            continue;
        }else{
            pos += a;
        }
        if(pos > curMax){
            ans += (ll)(cnt)*(min(pos * _gcd, n+1) - curMax * _gcd);
            curMax = pos;
        }
        cnt++;
    }while(pos != 0 && pos * _gcd <= n);
    if(curMax*_gcd <= n){
        ans += (ll)_gcd * ((n+1)/_gcd - curMax) * ((n+1)/_gcd + curMax + 1) / 2;
        ans += (ll)((n % _gcd + 1) % _gcd)*(n / _gcd + 1);
    }
    cout << ans;
    return 0;
}