#include "bits/stdc++.h"
using namespace std ;
string a , b ;
int cnt1[26] = {0} , cnt2[26] = {0};
int main(){
    cin >> a >> b;
    if(a == b){
        cout << "array";
    }
    else{
        for(char c : a){
            cnt1[c - 'a']++;
        }
        for(char c : b){
            cnt2[c - 'a']++;
        }
        for(int i = 0 ; i < 26 ; ++i){
            if(cnt2[i] > cnt1[i]){
                cout << "need tree";
                return 0;
            }
        }
        queue < char > q;
        for(char c : b){
            q.push(c);
        }
        for(char c : a){
            if(!q.empty() && q.front() == c){
                q.pop();
            }
        }
        if(q.empty()){
            cout << "automaton";
        }
        else{
            if(a.size() > b.size()){
                cout << "both";
            }
            else{
                cout << "array";
            }
        }
    }
}