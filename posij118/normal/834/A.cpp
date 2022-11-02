#include <bits/stdc++.h>
using namespace std;

int cislo(char c){
    if(c=='v') return 0;
    else if(c=='<') return 1;
    else if(c=='>') return 3;
    else return 2;
}

int main(){
    int n;
    char a, b;
    cin >> a >> b;
    cin >> n;

    if((cislo(a)%2)==(cislo(b)%2)) cout << "undefined";
    else if(((n-(cislo(a)-cislo(b)))%4)==0) cout << "ccw";
    else cout << "cw";

}