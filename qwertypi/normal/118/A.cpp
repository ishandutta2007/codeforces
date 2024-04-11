#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <iomanip>
#include <vector>
#include <ctype.h>
#define inf (1 << 30)
typedef long long ll;
using namespace std;

int cnt[51];
int main(){
    string s;
    cin >> s;
    for(auto i:s){
        if(isupper(i)){
            i ^= 32;
        }
        if(i != 'a' && i != 'e' && i != 'i' && i != 'o' && i != 'u' && i != 'y'){
            cout << '.' << i;
        }
    }
    return 0;
}