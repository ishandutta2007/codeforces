#include <vector>
#include <iostream>
#include <set>
#include <deque>
#include <utility>
#include <map>
#define MAX 100000
#define inf (1 << 30)
#define se second
#define fi first
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
#include <iostream>
#include <algorithm>
using namespace std;
int prec[101];
int main(){
    prec[0] = 0;
    int n;
    cin >> n;
    char s[100];
    cin >> s;
    for(int i=1; i<=n; i++){
        prec[i] = prec[i-1] + (s[i-1] == '+'?1:-1);
    }
    int _min = *min_element(prec, prec+n+1);
    int ans = prec[n] - _min;
    cout << ans;
}