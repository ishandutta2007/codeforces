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
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;



const string names[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};

int a[3];

void read(int& a){
    string s;
    cin>> s;
    for (int i=0;i<12;i++)
        if (names[i] == s)
            a=i;            
}



int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    read(a[0]);
    read(a[1]);
    read(a[2]);
    sort(a,a+3);
    do {
        if ((a[0] + 3)%12 == a[1] && (a[0] + 7)%12 == a[2]){
            printf("minor\n");
            return 0;
        }
        if ((a[0] + 4)%12 == a[1] && (a[0] + 7)%12 == a[2]){
            printf("major\n");
            return 0;
        }
            
    } while (next_permutation(a,a+3));
    printf("strange\n");
    return 0;
}