#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
    int n;
    cin >> n;
    string s;
    bool answ = false;
    set<string> two;
    set<string> three;
    set<string> thw;
    string q;
    for(int i = 1; i <= n; i ++ ){
        cin >> s;
        if(s.size() == 1){
            answ = true;
        }
        else{

            if(s.size() == 2){
                two.insert(s);

                q = s;
                reverse(q.begin(), q.end());
                if(two.count(q) || thw.count(q)){
                    answ = true;
                }
            }
            if(s.size() == 3){
                three.insert(s);

                q = s;
                reverse(q.begin(), q.end());
                if(three.count(q)){
                    answ = true;
                }
                q = "";
                q.push_back(s[0]);
                q.push_back(s[1]);
                thw.insert(q);
                q = "";
                q.push_back(s[2]);
                q.push_back(s[1]);
                if(two.count(q)){
                    answ = true;
                }

            }
        }
    }
    if(answ){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}