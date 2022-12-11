#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        string t;
        cin >> t;
        string sh = "Timur";
        sort(sh.begin(), sh.end());
        sort(t.begin(), t.end());
        if(sh == t){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}