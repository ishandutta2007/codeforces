#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <iomanip>
#include <vector>
#include <ctype.h>
#include <numeric>
#define inf (1 << 30)
typedef long long ll;
using namespace std;

int arr[1000000];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int res;
        cin >> arr[i] >> res;
    }
    ll ans = accumulate(arr, arr+n, 0LL);
    string res;
    while(ans > 500){
        ans -= 1000;
        res.push_back('G');
    }
    int left = n-(int)res.size();
    while(left-- > 0){
        res.push_back('A');
    }
    cout << res;
    return 0;
}