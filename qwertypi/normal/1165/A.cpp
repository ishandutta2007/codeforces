#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <deque>
#include <utility>
#include <numeric>
#include <map>
#define MAX 100000
#define inf (1 << 30)
#define se second
#define fi first
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    string real = s.substr(n-a, a);
    string cmp;
    for(int i=0;i<a;i++){
        if(i == a - b - 1){
            cmp.pb('1');
        }else{
            cmp.pb('0');
        }
    }
    int ans = 0;
    for(int i=0;i<a;i++){
        ans += cmp[i] != real[i];
    }
    cout << ans;
    return 0;
}