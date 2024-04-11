#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;

    while(q--){
        string s, t;
        bool flag = 0;
        cin >> s >> t;

        for(int i = 0; i<s.size(); i++){
            for(int j = i; j<s.size(); j++){
                string u;
                for(int k = i; k<=j; k++){
                    u += s[k];
                    if(u.size() == t.size()){
                        if(u == t && !flag){
                            cout << "YES" << endl;
                            flag = 1;
                        }
                    }
                }

                for(int k = j - 1; k>=0; k--){
                    u += s[k];
                    if(u.size() == t.size()){
                        if(u == t && !flag){
                            cout << "YES" << endl;
                            flag = 1;
                        }
                    }
                }
            }
        }

        if(!flag) cout << "NO" << endl;
    }

}