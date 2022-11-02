#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int minl, maxr, ans, maxrq;
    ans=0;
    for(int i=0; i<s.size(); i++){
        minl=0;
        maxr=0;
        maxrq=0;
        for(int j=i; j<s.size(); j++){
            if(s[j]=='(') minl++;
            if(s[j]==')') maxr++;
            if(maxr>minl){
                maxrq--;
                maxr--;
                minl++;
            }

            if(maxrq<0) break;

            if(s[j]=='?'){
                if(minl==maxr) minl++;
                else if(minl>maxr){
                    maxr++;
                    maxrq++;
                }
            }

            if(minl==maxr) ans++;
        }
    }

    cout << ans;

}