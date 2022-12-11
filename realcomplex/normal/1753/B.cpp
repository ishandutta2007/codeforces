#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 10;
int A[N];

int main(){
    fastIO;
    int n, x;
    cin >> n >> x;
    int a;
    for(int i = 1; i <= n; i ++ ){
        cin >> a;
        A[a] ++ ;
    }
    for(int i = 1; i < x; i ++ ){
        A[i+1] += A[i]/(i + 1);
        A[i] %= (i + 1);
        if(A[i] != 0){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}