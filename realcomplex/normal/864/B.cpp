#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define IMAX INT_MAX
#define IMIN INT_MIN
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define abs(a) ((a>0) ? a : -a)

const ld PI = acos(-1);
const ll MOD = ll(1e9) + 7;

/********************************/

void Solution(){
    IO;
    int n;
    cin >> n;
    char cur;
    set<char>q;
    int ans = 0;
    for(int i = 0;i<n;i++){
        cin >> cur;
        if(cur>='A' and cur<='Z'){
            q.clear();
        }
        else{
            q.insert(cur);
        }
        ans = max(ans,(int)q.size());
    }
    cout << ans << "\n";
}

/*******************************/

int main(){
    Solution();
    return 0;
}