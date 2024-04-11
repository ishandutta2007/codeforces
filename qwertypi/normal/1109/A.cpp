#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#define inf (1 << 14)
#define sz(x) (int)x.size()
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
#define MAX 300001

int prec[MAX];
int arr[MAX];
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    prec[0] = 0;
    for(int i=1;i<=n;i++){
        prec[i] = prec[i-1]^arr[i];
    }
    map<int, int> odd;
    map<int, int> even;
    for(int i=0;i<=n;i++){
        if(i%2){
            if(odd.find(prec[i]) != odd.end()){
                odd.find(prec[i])->se++;
            }else{
                odd[prec[i]] = 1;
            }
        }else{
            if(even.find(prec[i]) != even.end()){
                even.find(prec[i])->se++;
            }else{
                even[prec[i]] = 1;
            }
        }
    }
    ll ans = 0;
    for(auto i:odd){
        ans += (ll)i.se*(i.se-1) / 2;
    }
    for(auto i:even){
        ans += (ll)i.se*(i.se-1) / 2;
    }
    cout << ans;
    return 0;
}