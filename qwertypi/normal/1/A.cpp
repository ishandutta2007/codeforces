#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <iomanip>
#include <vector>
#define inf (1 << 30)
typedef long long ll;
using namespace std;

int cnt[51];
int main(){
    int n, m, a;
    cin >> n >> m >> a;
    cout << (ll)((n+a-1)/a) * ((m+a-1)/a);
    return 0;
}