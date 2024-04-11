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

string s1;
string s2;
int main(){
    cin >> s1 >> s2;
    bool t1 = count(s1.begin(), s1.end(), '1') == 0;
    bool t2 = count(s2.begin(), s2.end(), '1') == 0;
    string ans = (!(t1 ^ t2) && (s1.size() == s2.size()))?"YES":"NO";
    cout << ans;
    return 0;
}