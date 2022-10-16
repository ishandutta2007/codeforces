#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 1e5+500;

string bulb = "Bulbasaur";
map < char,int> cnt;
string s;
int sol = MAXN;

int main(){
    cin >> s;
    for(int i = 0;i<s.size();i++){
        cnt[s[i]]++;
    }
    for(int i = 0;i<bulb.size();i++){
        if(bulb[i] == 'a' || bulb[i] == 'u'){
            sol = min(sol,cnt[bulb[i]]/2);
        }
        else{
            sol = min(sol,cnt[bulb[i]]);
        }
    }
    cout << sol << endl;
}