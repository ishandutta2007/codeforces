#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

li a, b, c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    cout << 3 * min(a+1, min(b, c-1));
}