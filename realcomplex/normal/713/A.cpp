#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e18

void open(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin >> q;
    unordered_map<string,int>cnt;
    char k;
    string s;
    for(int j = 0;j<q;j++){
        cin >> k;
        if(k == '+'){
            cin >> s;
            for(int x = 0;x<s.size();x++){
                s[x] = (s[x]%2)+48;
            }
            reverse(s.begin(),s.end());
            while(s.size() > 1 && s[s.size()-1] == '0'){
                s.erase(s.size()-1,1);
            }
            while(s.size()<=18){
                cnt[s]++;
                s += "0";
            }
        }
        else if(k == '-'){
            cin >> s;
            for(int x = 0;x<s.size();x++){
                s[x] = (s[x]%2)+48;
            }
            reverse(s.begin(),s.end());
            while(s.size() > 1 && s[s.size()-1] == '0'){
                s.erase(s.size()-1,1);
            }
            while(s.size()<=18){
                cnt[s]--;
                s += "0";
            }
        }
        else{
            cin >> s;
            reverse(s.begin(),s.end());
            cout << cnt[s] << "\n";
        }
    }
    return 0;
}