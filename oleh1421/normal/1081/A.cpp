#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
typedef long long ll;
using namespace std;

bool p(string s){
     string s1=s;
     reverse(s1.begin(),s1.end());
     if (s==s1) return 1;
     return 0;
}
int main()
{
    ll v;cin>>v;
    if (v!=2) cout<<1;
    else cout<<2;
    return 0;
}