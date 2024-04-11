#include <iostream>
#include <vector>

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
        char b;
        vector<int> pos;
        vector<int> m(n * 2);
        vector<char> bb(n * 2);
        int res = 0;
        for(int i = 0 ; i < n * 2; i ++ ){
            cin >> b;
            bb[i] = b;
            res ++ ;
            if(b == '('){
                pos.push_back(i);
            }
            else{
                m[i] = pos.back();
                res -- ;
                if(m[i] > 0){
                    if(bb[m[i] - 1] == ')'){
                        res -- ;
                    }
                }
                pos.pop_back();
            }
        }

        cout << res << "\n";
    }
    return 0;
}