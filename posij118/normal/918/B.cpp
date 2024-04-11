#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, a, b, c, d;
    char x;
    string s;
    cin >> n >> m;

    map<pair<pair<int, int>, pair<int, int> >, string> ma;

    for(int i=0; i<n; i++){
        cin >> s >> a >> x >> b >> x >> c >> x >> d;
        ma[make_pair(make_pair(a, b), make_pair(c, d))]=s;


    }

    for(int i=0; i<m; i++){
        cin >> s >> a >> x >> b >> x >> c >> x >> d >> x;
        cout << s << " " << a << '.' << b << '.' << c << '.' << d << "; #" << ma[make_pair(make_pair(a, b), make_pair(c, d))] << endl;
    }

}