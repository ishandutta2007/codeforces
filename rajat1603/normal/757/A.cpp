#include "bits/stdc++.h"
using namespace std;
string bul = "Bulbasaur";
const int N = 1e5 + 5;
char str[N];
int ans;
map < char , int > mp;
int main(){
    scanf("%s" , str);
    int n = strlen(str);
    mp.clear();
    for(int i = 0 ; i < n ; ++i){
        ++mp[str[i]];
    }
    while(1){
        for(char c : bul){
            if(mp[c] > 0){
                --mp[c];
            }
            else{
                cout << ans << endl;
                return 0;
            }
        }
        ++ans;
    }
}