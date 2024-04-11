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
    for(int t = 1; t <= tc; t ++ ){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> a[i];
        }
        vector<int> q(n);
        int sum = 0;
        int sol;
        for(int i = 1; i + 1 < n; i ++ ){
            if(a[i] > a[i - 1] && a[i] > a[i + 1]){
                q[i]=1;
            }
            else if(a[i] < a[i - 1] && a[i] < a[i + 1]){
                q[i]=1;
            }
            sum += q[i];
        }
        sol = sum;
        int cur;
        int mid;
        int nx;
        for(int i = 0 ; i < n; i ++ ){
            set<int> cand;
            cur = sum-q[i];
            mid = a[i];
            if(i){
                cur -= q[i-1];
                cand.insert(a[i-1]+1);
                cand.insert(a[i-1]-1);
                cand.insert(a[i-1]);
            }
            if(i + 1 < n){
                cur -= q[i+1];
                cand.insert(a[i+1]+1);
                cand.insert(a[i+1]-1);
                cand.insert(a[i+1]);
            }
            for(auto x : cand){
                a[i] = x;
                nx = cur;
                for(int j = -1; j <= 1; j ++ ){
                    if(i + j > 0 && i + j + 1 < n){
                        if(a[i + j] > a[i + j - 1] && a[i + j] > a[i + j + 1]) nx ++ ;
                        else if(a[i + j] < a[i + j - 1] && a[i + j] < a[i + j + 1]) nx ++ ;
                    }
                }
                sol = min(sol, nx);
            }
            a[i]=mid;
        }
        cout << sol << "\n";
    }
    return 0;
}