#include <bits/stdc++.h>
using namespace std;

int main(){
    int ptr=0;
    string s;
    cin >> s;
    int used [s.size()];
    fill(used, used + s.size(), 0);

    for(int i=0; i<26; i++){
        while(1){

            if(ptr>=s.size()){
                cout << "-1";
                return 0;
            }

            if(s[ptr]-'a'<=i){
                while(s[ptr] < 'a' + i) s[ptr]++;
                ptr++;
                break;
            }

            ptr++;
        }


    }

    cout << s;

}