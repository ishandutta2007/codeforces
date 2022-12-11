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
        int n, m;
        cin >> n >> m;
        if(m < n){
            cout << "No\n";
        }
        else{
            if(m == n){
                cout << "Yes\n";
                for(int i = 1; i <= n ; i ++ ){
                    cout << 1 << " ";
                }
                cout << "\n";
            }
            else if(m == n + 1){
                if((n - 1) % 2 == 0){
                    cout << "Yes\n";
                    for(int i = 1; i <= n; i ++ ){
                        if(i < n) cout << 1 << " ";
                        else cout << 2 << "\n";
                    }
                }
                else{
                    cout << "No\n";
                }
            }
            else{
                vector<int> x(n);
                for(int i = 0 ; i < n; i ++ ){
                    if(i + 1 < n) x[i] = 1;
                    else x[i] = m - (n - 1);
                }
                if((n - 1) % 2 == 0){
                    cout << "Yes\n";
                    for(int i = 0 ; i < n; i ++ ) cout << x[i] << " ";
                    cout << "\n";
                }
                else{
                    if(m % 2 != 0){
                        cout << "No\n";
                    }
                    else{
                        cout << "Yes\n";
                        for(int i = 0 ; i < n; i ++ ){
                            if(i < n - 2){
                                cout << 1 << " ";
                            }
                            else{
                                cout << (m - (n - 2)) / 2 << " ";
                            }
                        }
                        cout << "\n";
                    }
                }
            }
        }
    }
    return 0;
}