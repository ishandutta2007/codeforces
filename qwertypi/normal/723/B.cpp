#include <iostream>
#define sz(n) (int)n.size()
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int longest = 0;
    int inside = 0;
    int para = 0;
    int curLen = 0;
    for(auto i:s){
        switch(i){
        case '(':
            para++;
            longest = max(longest, curLen);
            curLen = 0;
            break;
        case ')':
            para--;
            inside += curLen > 0;
            curLen = 0;
            break;
        case '_':
            if(para){
                inside += curLen > 0;
            }else{
                longest = max(longest, curLen);
            }
            curLen = 0;
            break;
        default:
            curLen++;
        }
    }
    longest = max(longest, curLen);
    cout << longest << ' ' << inside;
    return 0;
}