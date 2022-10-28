#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
char str[N];
int ans;
int main(){
    scanf("%d" , &n);
    scanf("%s" , str);
    ans = 1;
    char curx = '$';
    char cury = '$';
    for(int i = 0 ; i < n ; ++i){
        char c = str[i];
        if(c == 'L' || c == 'R'){
            if(curx == '$'){
                curx = c;
            }
            else if(curx != c){
                ++ans;
                cury = '$';
                curx = c;
            }
        }
        else{
            if(cury == '$'){
                cury = c;
            }
            else if(cury != c){
                ++ans;
                curx = '$';
                cury = c;
            }
        }
    }
    printf("%d\n" , ans);
}