#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

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
        string q[3];
        cin >> q[0] >> q[1] >> q[2];
        int p[3];
        p[0] = p[1] = p[2] = 0;
        int cnt;
        string sol;
        while(1){
            cnt = 0;
            for(int i = 0 ; i < 3; i ++ ){
                if(p[i] == n * 2) cnt ++ ;
            }
            if(cnt >= 2) break;
            if(cnt == 1){
                int id = -1;
                for(int i = 0 ; i < 3; i ++ ){
                    if(p[i] == n * 2) continue;
                    if(id == -1 || p[i] > p[id])
                        id = i;
                }
                while(p[id] < n * 2){
                    sol.push_back(q[id][p[id]]);
                    p[id] ++ ;
                }
                break;
            }
            else{
                int c0 = 0, c1 = 0;
                for(int i = 0 ; i < 3; i ++ ){
                    if(q[i][p[i]] == '0') c0 ++ ;
                    else c1 ++ ;
                }
                char use = '0';
                if(c0 >= 2){
                    sol.push_back('0');
                }
                else{
                    use = '1';
                    sol.push_back('1');
                }
                for(int i = 0 ; i < 3; i ++ ){
                    if(q[i][p[i]] == use) p[i] ++ ;
                }
            }
        }
        cout << sol << "\n";
    }
    return 0;
}