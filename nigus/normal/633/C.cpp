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
ll bp = 2147483647ll;
ll n,m,k,q;
ll T;
std::vector<string> A;
std::vector<string> B;
std::vector<ll> H;
std::map<ll,ll> M;
std::set<ll> S;
string s;

std::vector<ll> ANS;
bool fail = 1;
ll nu;

std::vector<ll> DP;

ll to(ll a,ll b){
if(b == 0){return 1;}
ll x = to(a,b/2);
if(b % 2 == 0){return (x*x)%bp;}
else{return (((x*x)%bp)*a)%bp;}
}

ll h(string sh){
    ll ans = 0;
    for(ll c = 0; c < sh.length(); c++){
        ans += ((char(sh[c])-96) * to(26,c)) % bp;
    }
return ans;
}

char tl(char ch){
if(ch == 'A'){return 'a';}
if(ch == 'B'){return 'b';}
if(ch == 'C'){return 'c';}
if(ch == 'D'){return 'd';}
if(ch == 'E'){return 'e';}
if(ch == 'F'){return 'f';}
if(ch == 'G'){return 'g';}
if(ch == 'H'){return 'h';}
if(ch == 'I'){return 'i';}
if(ch == 'J'){return 'j';}
if(ch == 'K'){return 'k';}
if(ch == 'L'){return 'l';}
if(ch == 'M'){return 'm';}
if(ch == 'N'){return 'n';}
if(ch == 'O'){return 'o';}
if(ch == 'P'){return 'p';}
if(ch == 'Q'){return 'q';}
if(ch == 'R'){return 'r';}
if(ch == 'S'){return 's';}
if(ch == 'T'){return 't';}
if(ch == 'U'){return 'u';}
if(ch == 'V'){return 'v';}
if(ch == 'W'){return 'w';}
if(ch == 'X'){return 'x';}
if(ch == 'Y'){return 'y';}
if(ch == 'Z'){return 'z';}
return ch;
}

bool F(ll i,ll nu2){
if(i == m){fail = 0;nu = nu2; return 1;}
if(DP[i] != -1){return DP[i];}
ll h = 0;
//cout << i << " " << nu2 << "\n";
for(ll c = i; c < m; c++){
    h += ((char(s[c])-96) * to(26,c-i)) % bp;
    if(S.find(h) != S.end()){
        if(F(c+1, nu2+1) == 1){
        ANS[nu2] = M[h];
        DP[i] = 1;
        return 1;
        }
    }
}
DP[i] = 0;
return 0;
}

int main()
{
    ll c1,c2,c3,c4,c5;
    ll x,y,z;
    ll a,b,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    std::cin >> m;
    std::cin >> s;
    std::cin >> n;
    m = s.length();
    for(c1=0;c1<n;c1++){
        string s2;
        string s3 = "";
        std::cin >> s2;
        A.push_back(s2);
        for(c2 = s2.length()-1; c2 >= 0; c2--){
            s3 += tl(s2[c2]);
        }

        B.push_back(s3);
        S.insert(h(s3));
        M[h(s3)] = c1;
        ANS.push_back(0);

    }

    for(c1=0;c1<6+m;c1++){ANS.push_back(0);DP.push_back(-1);}

    nu = 0;
    F(0,0);

   for(c1=0;c1<nu;c1++){
        std::cout << A[ANS[c1]] << " ";
   }



	return 0;
}