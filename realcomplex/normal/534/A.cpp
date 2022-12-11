#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    if(n <= 2) cout << "1\n1";
    else if(n == 3) cout << "2\n1 3";
    else{
        int k = n;
        cout << k << "\n";
        int p = 1+(1-(n%2));
        for(int j = 0;j<k;j++){
            cout << p << " ";
            p+=2;
            if(p>n){
                p = 1+(n%2);
            }
        }
    }
    return 0;
}