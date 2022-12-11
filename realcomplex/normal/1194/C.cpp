#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int AL = 26;
vector<int> pos[AL];
int cnt[AL];

int main(){
    fastIO;
    int testc;
    cin >> testc;
    for(int tt = 0 ;tt < testc; tt ++ ){
        string s, t, p;
        cin >> s >> t >> p;
        for(int j = 0 ; j < AL; j ++ ){
            pos[j].clear();
            cnt[j] = 0;
        }
        for(int i = (int)t.size() - 1 ; i >= 0; i-- ){
            pos[t[i] - 'a'].push_back(i);
            cnt[t[i] - 'a'] ++ ;
        }
        bool ok = true;
        int ps = -1;
        for(int i = 0 ; i < s.size(); i ++ ){
            while(!pos[s[i] - 'a'].empty()){
                if(pos[s[i] - 'a'].back() <= ps)
                    pos[s[i] - 'a'].pop_back();
                else
                    break;
            }
            if(pos[s[i] - 'a'].empty())
                ok = false;
            else
                ps = pos[s[i] - 'a'].back();
            cnt[s[i] - 'a'] -- ;
        }
        for(char v : p){
            cnt[v - 'a'] -- ;
        }
        for(int j = 0 ; j < AL ; j ++ )
            if(cnt[j] > 0)
                ok = false;
        if(ok)
            cout << "Yes\n";
        else
            cout << "No\n";
    
    }
    return 0;
}