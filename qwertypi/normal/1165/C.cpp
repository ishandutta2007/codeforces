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

char s[200002];
bool use[200000];
int main(){
    fill(use, use+200000, 0);
    int n;
    cin >> n;
    cin >> s;
    string ans;
    int ind = 0;
    while(n > ind){
        char first = s[ind];
        char second = '\0';
        ind++;
        while(ind < n){
            if(s[ind] != first){
                second = s[ind];
                ind++;
                break;
            }
            ind++;
        }
        if(second == '\0'){
            break;
        }
        ans.pb(first);
        ans.pb(second);
    }
    cout << n - (int)ans.size() << endl;
    cout << ans;
    return 0;
}