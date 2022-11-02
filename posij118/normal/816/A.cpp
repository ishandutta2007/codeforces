#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int h, m;
    char bla;
    cin >> h;
    cin >> bla;
    cin >> m;

    int a;
    a=0;
    while(1){
        if(h%10 == m/10 && h/10 == m%10) break;
        else{
            if(h==23 && m==59){
                h=0;
                m=0;
            }

            else if(m==59){
                h++;
                m=0;
            }
            else m++;

            a++;
        }
    }

    cout << a;
}