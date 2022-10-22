#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

li n;
set<li> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=sqrt(n); i++){
        if (n%i != 0) continue;
        li k = n/i;
        li a = ((k-1)*i + 2)*k/2;
        li b = ((i-1)*k + 2)*i/2;
        s.insert(a);
        s.insert(b);
    }
    for (set<li>::iterator it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
}