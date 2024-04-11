#include <iostream>
#include <string>
using namespace std;

int main(){
    int k, i, j = 'a'; cin >> k;
    if (k == 0) return cout << "a", 0;
    string ans = "";
    while (k > 0){
        i = 0;
        while (k >= i) k -= i++, ans.push_back(char(j));
        j++;
    }
    cout << ans;
}