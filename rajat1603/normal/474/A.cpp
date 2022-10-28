#include "bits/stdc++.h"
using namespace std;
string s = "qwertyuiopasdfghjkl;zxcvbnm,./";
char type;
string str;
int val;
map < char , int > pos;
int i = 0;
int main(){
    for(auto it : s){
        pos[it] = i++;
    }
    cin >> type;
    val = (type == 'R') ? 1 : -1;
    cin >> str;
    for(auto it : str){
        printf("%c" , s[pos[it] - val]);
    }
}