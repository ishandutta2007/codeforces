                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
#include <set>
#include <map>
using namespace std;

#define int64 long long
#define P pair<int, int>

int n, cnt;
map <int, int> mp;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    cin >> n;
    int h, m;
    for(int i = 0; i < n; i++){
        cin >> h >> m;
        mp[h * 60 + m]++;
        cnt = max(cnt, mp[h * 60 + m]);
    }
    cout << cnt << endl;
    return 0;
}