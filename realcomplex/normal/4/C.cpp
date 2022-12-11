#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);cin.tie(false);
    int n;
    cin >> n;
    map<string,int>val;
    string s;
    int g;
    for(int i = 0;i<n;i++){
        cin >> s;
        g = val[s];
        if(g==0){
            cout << "OK\n";
        }
        else{
            cout << s << g << "\n";
        }
        val[s]++;
    }
    return 0;
}