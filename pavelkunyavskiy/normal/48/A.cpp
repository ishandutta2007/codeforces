#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define int64 long long
#define ld long double  
#define setval(a,v) memset(a,v,sizeof(a))
using namespace std;

const string names[3]={"rock","paper","scissors"};
const string gamers[3]={"F","M","S"};

string s[3];
int num[3];

int main()
{                        
    for (int i=0;i<3;i++){
        cin>>s[i];
        for (int j=0;j<3;j++)
            if (s[i]==names[j])
                num[i]=j;
    }
    if (num[0]==(num[1]+1)%3 && num[0]==(num[2]+1)%3)
        cout<<gamers[0]<<endl;      
    else if (num[1]==(num[0]+1)%3 && num[1]==(num[2]+1)%3)
        cout<<gamers[1]<<endl;
    else if (num[2]==(num[0]+1)%3 && num[2]==(num[1]+1)%3)
        cout<<gamers[2]<<endl;
    else
        cout<<"?"<<endl;

    return 0;
}