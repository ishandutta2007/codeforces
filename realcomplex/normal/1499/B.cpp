#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int>pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int it = 1; it <= tc; it ++ ){
        string s;
        cin >> s;
        bool was = false;
        int mx = 0;
        bool soln = true;
        int id = 0;
        for(char x : s){
            id ++ ;
            if(x == '0'){
                if(mx == 1){
                    if(was){
                        soln = false;
                        break;
                    }
                    else{
                        was = true;
                    }
                }
                else{
                    was = false;
                }
            }
            else{
                if(mx == 1){
                    was = false;
                }
                else{
                    if(!was) was = true;
                    else mx = 1, was = false;
                }
            }
        }
        if(soln)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}