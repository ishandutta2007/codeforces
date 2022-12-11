#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second


int main()
{
    int n;
    cin >> n;
    vector<int>s[3];
    int sk;
    for(int i = 0;i<n;i++){
        cin >> sk;
        s[sk-1].push_back(i+1);
    }
    if(s[0].size() <= s[1].size() && s[0].size() <= s[2].size()){
        cout << s[0].size() << "\n";
        for(int i = 0;i<s[0].size();i++){
            cout << s[0][i] << " " << s[1][i] << " " << s[2][i] << "\n";
        }
    }
    else if(s[0].size() >= s[1].size() && s[1].size() <= s[2].size()){
        cout << s[1].size()<< "\n";
        for(int i = 0;i<s[1].size();i++){
            cout << s[0][i] << " " << s[1][i] << " " << s[2][i] << "\n";
        }
    }
    else{
        cout << s[2].size()<< "\n";
        for(int i = 0;i<s[2].size();i++){
            cout << s[0][i] << " " << s[1][i] << " " << s[2][i] << "\n";
        }
    }
    return 0;
}