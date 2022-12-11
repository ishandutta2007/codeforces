#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int A[N];
int X[N];
map<int, vector<int>> F[2];

bool check(int pari, int val, int li, int ri){
    int id = lower_bound(F[pari][val].begin(), F[pari][val].end(), li) - F[pari][val].begin();
    if(id == F[pari][val].size() || F[pari][val][id] > ri) return false;
    return true;
}

int main(){
    fastIO;
    int n, q;
    cin >> n >> q;
    set<int> Z;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        X[i] = (A[i] ^ X[i - 1]);
        if(A[i] != 0) Z.insert(i);
    }
    for(int i = 0 ; i <= n; i ++ ){
        F[i % 2][X[i]].push_back(i);
    }
    int li, ri;
    int pp;
    for(int ii = 1; ii <= q; ii ++) {
        cin >> li >> ri;
        if((X[ri] ^ X[li - 1]) == 0){
            auto it = Z.lower_bound(li);
            if(it == Z.end() || *it > ri){
                cout << "0\n";
            }
            else{
                if((ri - li + 1) % 2 == 1 || A[li] == 0 || A[ri] == 0){
                    cout << "1\n";
                }
                else{
                    pp = (((li - 1) & 1) ^ 1);
                    if(check(pp, X[li - 1], li, ri)){
                        cout << "2\n";
                        continue;
                    }
                    pp = ((ri & 1) ^ 1);
                    if(check(pp, X[ri], li - 1, ri - 1)){
                        cout << "2\n";
                        continue;
                    }
                    cout << "-1\n";

                }
            }
        }
        else{
            cout << "-1\n";
        }
    }
    return 0;
}