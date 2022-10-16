#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef long long int llint;
typedef pair < int,int> pii;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int M = 1e6 + 500;

vector < string > v;
string s1,s2;

int main(){
    cin >> s1 >> s2;
    for(int i = 1;i<=s1.size();i++)
        for(int j = 1;j<=s2.size();j++)
            v.push_back(s1.substr(0,i) + s2.substr(0,j));
    sort(v.begin(),v.end());
    cout << v[0] << endl;
}