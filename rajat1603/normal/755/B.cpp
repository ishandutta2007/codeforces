#include "bits/stdc++.h"
using namespace std;
int n , m;
char str[505];
set < string > s1;
set < string > s2;
int com;
int a , b;
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%s" , str);
        s1.insert(str);
    }
    com = 0;
    a = n;
    b = 0;
    for(int i = 1 ; i <= m ; ++i){
        scanf("%s" , str);
        if(s1.find(str) == s1.end()){
            ++b;
        }
        else{
            --a;
            if(com){
                com = 0;
            }
            else{
                com = 1;
            }
        }
    }
    a += com;
    if(a > b){
        cout << "YES\n";
    }
    else{
        cout << "NO";
    }
}