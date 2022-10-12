#include<bits/stdc++.h>
using namespace std;

int main(){
    long s[5];
    int i;
    for(i=0; i<4; i++) cin >> s[i];
    sort(s, s+4);
    cout << 4 - (unique(s, s+4) - s) << endl;
    return 0;
}