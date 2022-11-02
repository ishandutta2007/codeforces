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

char magic[5] = {'a', 'e', 'i', 'o', 'u'};
vector<int> factor;
int main(){
    int n;
    cin >> n;
    int i=1;
    while(i*i <= n){
        if(n % i == 0){
            factor.pb(i);
        }
        i++;
    }
    int l = factor.back();
    int r = n / factor.back();
    if(l >= 5 && r >= 5){
        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                cout << magic[(i+j) % 5];
            }
        }
    }else{
        cout << -1;
    }
    return 0;
}