#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <stdio.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll n,m,k,q,d;
ll T;



std::vector<string> A;
std::vector<char> B;
std::set<string> S;

ll dfs(string s , ll d){

//cout << s << "\n";
if(d == n){
        if(S.find(s) != S.end()){return 0;}
        S.insert(s);
        return 1;
}
ll sum = 0;
string s2;
for(ll c1 = 0; c1 < q; c1++){

    if(s[0] == B[c1]){
        s2 = s;
        s2[0] = A[c1][1];
        s2 = A[c1][0] + s2;
        if(S.find(s2) == S.end()){
            sum += dfs(s2, d+1);
        }
    }
}
S.insert(s);
return sum;

}

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll x,y,z;
    ll a,b,c,e;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    std::cin >> n >> q;
    string s;
    char ch;
    for(c1 = 0; c1 < q ; c1++){
        std::cin >> s >> ch;
        A.push_back(s);
        B.push_back(ch);
    }


std::cout << dfs("a" , 1) << "\n";

	return 0;
}