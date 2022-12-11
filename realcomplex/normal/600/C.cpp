#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second

int k[26];

int main()
{
    string s;
    cin >> s;
    string ans;
    for(int i = 0;i<int(s.size());i++){
        k[s[i]-97]++;
        ans += '?';
    }
    for(int y = 25;y>=0;y--){
        if(k[y]%2==1){
            for(int i = 0;i<y;i++){
                if(k[i]%2==1){
                    k[i]++;
                    k[y]--;
                    break;
                }
            }
        }
    }
    int p1,p2;
    p1 = 0;
    p2 = s.size()-1;
    for(int i = 0;i<26;i++){
        if(k[i]%2==1){
            ans[s.size()/2] = char(i+97);
            k[i]--;
        }
        while(k[i] > 0){
            k[i]-=2;
            ans[p1] = char(i+97);
            ans[p2] = char(i+97);
            p1++;
            p2--;
        }
    }
    cout << ans;
    return 0;
}