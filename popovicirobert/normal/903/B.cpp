#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

vector < string > sol;

int main(){
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int h1, a1, c1, h2, a2;
    ios::sync_with_stdio(false);
    cin >> h1 >> a1 >> c1;
    cin >> h2 >> a2;
    while(h2 > 0) {
        if(a1 >= h2) {
            sol.push_back("STRIKE");
            h2 -= a1;
        }
        else if(a2 >= h1) {
            sol.push_back("HEAL");
            h1 += c1;
        }
        else {
            sol.push_back("STRIKE");
            h2 -= a1;
        }
        h1 -= a2;
    }
    cout << sol.size() << endl;
    for(auto it : sol)
        cout << it << endl;
    //cin.close();
    //cout.close();
    return 0;
}