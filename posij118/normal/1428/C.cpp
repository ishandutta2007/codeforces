#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        vector<int> as;
        vector<int> pos;

        int cnta, cntb;
        cntb = 0;

        for(int i = 0; i<s.size(); i++){
            if(s[i] == 'A'){
                as.push_back(i);
            }

            if(s[i] == 'B'){
                if(as.size()){
                    int x = as.back();
                    as.pop_back();
                    pos.push_back(x);
                    pos.push_back(i);
                }

                else{
                    cntb++;
                }
            }
        }
        cout << (cntb % 2) + as.size() << endl;


    }

}