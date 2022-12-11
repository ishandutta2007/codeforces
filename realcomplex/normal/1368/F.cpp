#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair

int main(){
    int n;
    cin >> n;
    if(n <= 3){
        cout << 0 << endl;
        return 0;
    }
    int best = 0, opt = 0;
    int cur;
    for(int k = 2; k <= n; k ++ ){
        vector<bool> sol(n);
        cur = 0;
        for(int i = 0 ; i < n; i += k ){
            if(i % k == 0){
                sol[i] = true;
            }
        }
        for(int i = 0 ; i < n; i ++ ){
            if(!sol[i]){
                cur ++ ;
            }
        }
        cur -= (k-1);
        if(cur > best){
            best = cur;
            opt = k;
        }
    }
    vector<bool> tata(n);
    int cnt = 0;
    int sha;
    while(cnt < best){
        vector<int> lis;
        for(int i = 0 ; i < n; i ++ ){
            if(i % opt == 0) continue;
            if(!tata[i]) {
                if(lis.size() < opt){
                    lis.push_back(i);
                    tata[i]=true;
                    cnt ++ ;
                }
            }
        }

        cout << lis.size() << " ";
        for(auto x : lis)
            cout << x + 1 << " ";
        cout << endl;
        cin >> sha;
        sha -- ;
        for(int g = 0; g < lis.size(); g ++ ){
            if(tata[sha]){
                tata[sha]=false;
                cnt--;
            }
            sha ++;
            sha %= n;
        }
    }
    cout << 0 << endl;
    return 0;
}