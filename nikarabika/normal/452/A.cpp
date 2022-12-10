#include <iostream>
#include <stdlib.h>

using namespace std;

#define FOR(i, begin, end) for(ll i=begin; i<end; i++)
#define sp system("pause")
#define r(x) return x

typedef long long int ll;

string A[]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main()
{
    int n;
    string B;
    cin>>n;
    cin>>B;
    for(int i=0; i<8; i++)
    {
        if(A[i].length()==B.length())
        {
            bool x=true;
            FOR(j, 0, B.size())
            {
                if(B[j]!='.' && A[i][j]!=B[j])
                    x=false;
            }
            if(x)
            {
                cout<<A[i]<<endl;
                r(0);
            }
        }
    }
    return 0;
}