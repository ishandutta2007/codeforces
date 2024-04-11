#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    ll n,x,Y,l,c,r2;
    int c1,c2,c3,c4;
    int a,b;
    string s,t;
    string out;
    std::cin >> s >> t;
    n=s.length();
    x=0;
    for(c1=0;c1<n;c1++){

        a=int(s[c1])-48;
        b=int(t[c1])-48;

        if(a!=b){x+=1;
        if(x%2==0){out += s[c1];}else{out += t[c1];}

        }
        else{out += t[c1];}



    }
    if(x%2==1){std::cout << "impossible\n";}
    else{

        std::cout << out << "\n";



    }

   return 0;
}