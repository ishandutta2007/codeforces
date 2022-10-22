#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

char a, b;
char x, y;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    for (int i=0; i<5; i++){
        cin >> x >> y;
        if (x == a || y == b){
                cout << "YES";
                return 0;
        }
    }
    cout << "NO";
}