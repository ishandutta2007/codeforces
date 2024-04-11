#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, maxi, cnt;
    cin >> n;
    x=0;
    maxi=0;

    vector<string> text;
    while(x<n){
        cnt=0;
        text.push_back("");
        cin >> text[text.size()-1];
        for(int i=0; i<text[text.size()-1].size(); i++){
            if(text[text.size()-1][i]<='Z') cnt++;
        }
        maxi=max(maxi, cnt);
        x+=text[text.size()-1].size()+1;

    }

    cout << maxi;

}