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
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        vector<ll> A(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> A[i];
        }
        bool soln;
        if(A[n - 2] > A[n - 1]){
            cout << "-1\n";
        }
        else{
            vector<int> x, y, z;
            soln = true;
            for(int i = n - 3; i >= 0 ; i -- ){
                if(A[i + 1] < A[i + 1] - A[n - 1] && A[i] > A[i + 1]){
                    soln = false;
                    cout << "-1\n";
                    break;
                }
                else{
                    if(A[i + 1] >= A[i + 1] - A[n - 1]){
                        for(int j = 0 ; j <= i; j ++ ){
                            x.push_back(j);
                            y.push_back(i+1);
                            z.push_back(n-1);
                        }
                        break;
                    }
                    else{
                        continue;
                    }
                }
            }
            if(soln){
                cout << x.size() << "\n";
                for(int i = 0 ; i < x.size(); i ++ ){
                    cout << x[i] + 1 << " " << y[i] + 1 << " " << z[i] + 1 << "\n";
                }
            }
        }
    }
    return 0;
}