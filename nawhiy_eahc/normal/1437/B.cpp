#include <iostream>
#include <string>

using namespace std;

int reverse(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt0=0, cnt1=0;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1] && s[i]=='1') cnt1++;
        if(s[i]==s[i+1] && s[i]=='0') cnt0++;
    }
    
    int result;
    if(cnt1<cnt0) result=cnt0;
    else result=cnt1;
    
    return result;
}

int main(){
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << reverse() << "\n";
    }
}