#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second

int main(){

    ios_base::sync_with_stdio(false);cin.tie();
    int n;
    cin >> n;
    int t;
    int speed = 0;
    int ans = 0;
    int c = 0;
    int bs;
    stack<int>s;
    cin >> t >> speed;
    for(int i = 1;i<n;i++){
        cin >> t;
        if(t == 1){
            cin >> speed;
            while(!s.empty() && speed>s.top()){
                s.pop();
                ans++;
            }
        }
        else if(t == 2){
            ans += c;
            c = 0;
        }
        else if(t == 3){
            cin >> bs;
            s.push(bs);
            if(bs < speed){
                s.pop();
                ans++;
            }
        }
        else if(t == 4){
            c = 0;
        }
        else if(t == 5){
            while(!s.empty()) s.pop();
        }
        else{
            c++;
        }
    }
    cout << ans;
    return 0;
}