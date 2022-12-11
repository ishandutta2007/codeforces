#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 10000000
#define mp make_pair
#define fi first
#define se second

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);
    string s;
    cin >> s >> s;
    deque<char>ans;
    if(s.size()%2==0){
        for(int i = 0;i<s.size();i++){
            if(i%2==1){
                ans.push_back(s[i]);
            }
            else{
                ans.push_front(s[i]);
            }
        }
    }
    else{
        for(int i = 0;i<s.size();i++){
            if(i%2==0){
                ans.push_back(s[i]);
            }
            else{
                ans.push_front(s[i]);
            }
        }
    }
    for(int j = 0;j<s.size();j++){
        cout << ans.front();
        ans.pop_front();
    }
    return 0;
}