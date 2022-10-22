#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int main()
{
    ll n,m,a,b,c,x,y;
    int c1,c2,c3,c4,q;
    std::cin >> n >> m >> q;


    bool s;

    std::vector<std::vector<int> > S(n , std::vector<int>());


    int M[501];



    for(c1=0;c1<n;c1++)
{
    for(c2=0;c2<m;c2++)
    {
        std::cin >> s;
        S[c1].push_back(s);
    }
}


for(c1=0;c1<n;c1++){
    c=0;
    M[c1]=0;
    for(c2=0;c2<m;c2++){
        c*=S[c1][c2];
        c+=S[c1][c2];
        if(c>M[c1]){M[c1]=c;}

    }

}


for(c1=0;c1<q;c1++){

    std::cin >> a >> b;
    x=a-1;
    y=b-1;
    S[x][y] = (S[x][y]+1)%2;

    c=0;
    M[x]=0;
    for(c2=0;c2<m;c2++){
        c*=S[x][c2];
        c+=S[x][c2];
        if(c>M[x]){M[x]=c;}

    }
    c=0;
    for(c2=0;c2<n;c2++){
            //std::cout << M[c2] << "\n";
        if(M[c2] > c){c=M[c2];}


    }
    std::cout << c << "\n";






}






   return 0;
}