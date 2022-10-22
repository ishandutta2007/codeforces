#include <bits/stdc++.h>
using namespace std;

string s[1001];
int a[1001];
map<string,int>mp,ma;

int main() {
    int n; cin >> n;
    for(int i=0; i<n; i++){
        cin >> s[i] >> a[i];
        mp[s[i]]+=a[i];
    }

    int mx=0;
    for(int i=0;i<n;i++){
        mx=max(mx,mp[s[i]]);
    }
    
    for(int i=0;i<n;i++){
        ma[s[i]]+=a[i];
        if(ma[s[i]]>=mx && mp[s[i]]==mx){
            cout << s[i] << endl;
            return 0;
        }
    }
 
}