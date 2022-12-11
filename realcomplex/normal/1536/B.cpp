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
    vector<string> al;
    for(char x = 'a'; x <= 'z'; x ++ ){
        string cur;
        cur.push_back(x);
        al.push_back(cur);
    }
     for(char x = 'a'; x <= 'z'; x ++ ){
        string cur;
        cur.push_back(x);
        for(char y = 'a'; y <= 'z'; y ++ ){
            cur.push_back(y);
            al.push_back(cur);
            cur.pop_back();
        }
    }
     for(char x = 'a'; x <= 'z'; x ++ ){
        string cur;
        cur.push_back(x);
        for(char y = 'a'; y <= 'z'; y ++ ){
            cur.push_back(y);
            for(char z = 'a'; z <= 'z'; z ++ ){
                cur.push_back(z);
                al.push_back(cur);
                cur.pop_back();
            }
            cur.pop_back();
        }
    }
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        string t;
        cin >> t;
        set<string> vse;
        for(int i = 0 ; i < n; i ++ ){
            string c;
            for(int j = 0 ; j <= 5; j ++ ){
                if(i + j < n){
                    c.push_back(t[i + j]);
                    vse.insert(c);
                }
            }
        }
        for(auto res : al){
            if(!vse.count(res)){
                cout << res << "\n";
                break;
            }
        }

    }
    return 0;
}