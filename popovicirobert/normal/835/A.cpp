#include <bits/stdc++.h>
#define ll long long


using namespace std;



int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int s,v1,v2,t1,t2;
    ios::sync_with_stdio(false);
    cin >> s >> v1 >> v2 >> t1 >> t2;
    if(s * v1 + 2 * t1 == s * v2 + 2 * t2)
        cout << "Friendship";
    else if(s * v1 + 2 * t1 < s * v2 + 2 * t2)
        cout << "First";
    else
        cout << "Second";
    //cin.close();
    //cout.close();
    return 0;
}