#include<bits/stdc++.h>
using namespace std;
string f(string a, string b, char X){
    string x;
    int i = 0, j = 0;
    a += '#'; b += '#';
    while(i < a.size()-1 || j < b.size()-1){
        if(a[i] == b[j]){
            x += a[i];
            i++;
            j++;
        }
        else if(a[i] == X || j == b.size()-1){
            x += a[i];
            i++;
        }
        else {
            x += b[j];
            j++;
        }
    }
    return x;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        string a,b,c;
        cin >> n >> a >> b >> c;
        string s = "";
        if(f(a,b,'0').size() <= 3*n) s = f(a,b,'0');
        if(f(b,c,'0').size() <= 3*n) s = f(b,c,'0');
        if(f(c,a,'0').size() <= 3*n) s = f(c,a,'0');
        if(f(a,b,'1').size() <= 3*n) s = f(a,b,'1');
        if(f(b,c,'1').size() <= 3*n) s = f(b,c,'1');
        if(f(c,a,'1').size() <= 3*n) s = f(c,a,'1');
        while(s.size() < 3*n) s += '0';
        cout << s << endl;
    }

}