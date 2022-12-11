#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        vector<int> que;
        int x;
        que.push_back(0);
        for(int i = 1; i <= n; i ++ ){
            cin >> x;
            if(x == que.back() + 1){
                que.pop_back();
                que.push_back(x);
            }
            else{
                if(x == 1){
                    que.push_back(1);
                }
                else{
                    while(que.back() + 1 != x){
                        que.pop_back();
                    }
                    que.pop_back();
                    que.push_back(x);
                }
            }
            for(int j = 0; j < que.size(); j ++ ){
                cout << que[j];
                if(j + 1 < que.size())
                    cout << ".";
            }
            cout << "\n";
        }
    }
    return 0;
}