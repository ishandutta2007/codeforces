#include <bits/stdc++.h>
using namespace std;
string s;
int x;
int main() {
    cin>>s>>x;
    if (s=="ABC") {
        if (x<2000) cout<<"YES"; else cout<<"NO"; 
    }
    else if (s=="ARC") {
        if (x<2800) cout<<"YES"; else cout<<"NO";
    }
    else {
        if (x>=1200) cout<<"YES"; else cout<<"NO";
    }
}