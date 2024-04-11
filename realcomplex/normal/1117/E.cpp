#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int AL = 26;

string ask(string t){
    cout << "? " << t << endl;
    fflush(stdout);
    string s;
    cin >> s;
    return s;
}

int f[AL][AL][AL];
int ini[AL][AL][AL];

int main(){
    fastIO;
    for(int i = 0 ; i < AL; i ++ ) for(int j = 0 ; j < AL; j ++ ) for(int z = 0; z < AL ;z ++ )
        f[i][j][z] = -1, ini[i][j][z] = -1;
    string t;
    cin >> t;
    int n = t.size();
    int cur = 0;
    string a1, a2, a3;
    for(int i = 0 ; i < AL; i ++ ){
        for(int j = 0 ; j < AL ; j ++ ){
            for(int z = 0 ; z < AL; z ++ ){
                if(cur == n)
                    continue;
                ini[i][j][z] = cur;
                cur ++ ;
                a1.push_back(char('a' + i));
                a2.push_back(char('a' + j));
                a3.push_back(char('a' + z));
            }
        }
    }
    a1 = ask(a1);
    a2 = ask(a2);
    a3 = ask(a3);
    for(int i = 0 ; i < n; i ++ ){
        f[a1[i] - 'a'][a2[i] - 'a'][a3[i] - 'a'] = i;
    }
    string ans;
    for(int i = 0 ; i < n;i ++ )
        ans.push_back('#');
    for(int i = 0 ;i < AL ; i ++ ){
        for(int j = 0 ; j < AL ; j ++ ){
            for(int z = 0 ;z < AL; z ++ ){
                if(f[i][j][z] != -1){
                    ans[ini[i][j][z]] = t[f[i][j][z]];
                }
            }
        }
    }
    cout << "! " << ans << endl;
    return 0;
}