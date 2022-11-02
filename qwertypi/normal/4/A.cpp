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
    int n;
    cin >> n;
    if(n % 2 == 0 && n > 2){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}