#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, f, p;
    cin >> s;
    cin >> f;
    p = s;
    int m = max(abs(f[1]-s[1]),abs(f[0]-s[0]));
    cout << m << endl;
    for(int i=0; i<m; i++){
        if (p[0] > f[0]) {cout << "L"; p[0]--;}
        else if (p[0] < f[0]) {cout << "R"; p[0]++;}

        if(p[1] > f[1]) {cout << "D"; p[1]--;}
        else if (p[1] < f[1]) {cout << "U"; p[1]++;}

        cout << endl;
    }

}