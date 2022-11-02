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

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int pos = -1;
        for(int i=0;i<n;i++){
            if(s[i] == '8'){
                pos = i;
                break;
            }
        }
        if(pos == -1 || n - 1 - pos < 10){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
    return 0;
}