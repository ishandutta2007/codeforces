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
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        string s;
        cin >> s;
        string dec;
        int num;
        int n1, n2;
        while(!s.empty()){
            num = s.back() - '0';
            s.pop_back();
            if(num == 0){
                n1 = s.back() - '0';
                s.pop_back();
                n2 = s.back() - '0';
                s.pop_back();
                n1 += n2 * 10;
                n1 -- ;
                dec.push_back(char('a' + n1));
            }
            else{
                dec.push_back(char(num + 'a' - 1));
            }
        }
        reverse(dec.begin(), dec.end());
        for(char x : dec){
            cout << x;
        }
        cout << "\n";
    }
    return 0;
}