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
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        if((int)s.size()>10){
            cout << s[0] << s.size()-2 << s[(int)s.size()-1] << endl;
        }else{
            cout << s << endl;
        }
    }
    return 0;
}