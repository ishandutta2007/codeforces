#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int s,sp,sp1,p1,p2;
    cin >> s >> sp >> sp1 >> p1 >> p2;
    int val = (p1*2) + (s*sp);
    int val2 = (p2*2) + (s*sp1);
    if(val == val2){
        cout << "Friendship";
    }
    else if(val < val2){
        cout << "First";
    }
    else{
        cout << "Second";
    }
    return 0;
}