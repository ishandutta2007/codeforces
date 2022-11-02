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
#define m 998244353
using namespace std;
typedef long long ll;
typedef long double ld;
using namespace std;

int cnt[26];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        cnt[s[0] - 'a']++;
    }
    int ans = 0;
    for(int i=0;i<26;i++){
        int a = cnt[i] / 2;
        int b = (cnt[i] + 1) / 2;
        ans += a * (a-1) + b * (b-1);
    }
    ans /= 2;
    cout << ans;
    return 0;
}